#include "Game.h"

Game::Game(int width, int height, int brick_sz):
	m_width(width),m_height(height),m_brick_sz(brick_sz),
	m_bricks(std::vector<pBrick>()),m_stopped(false),
	m_movingLeft(false), m_movingRight(false)
{
	srand (time(NULL));
	newPiece();
}


void Game::newPiece()
{
  Tetrimino_t pieceType=(Tetrimino_t)(rand()%(Z_TETRIMINO+1));
	m_piece=std::make_shared<Tetrimino>(4*m_brick_sz,0,m_brick_sz,pieceType);
}

void Game::show(SDL_Renderer* rndr)
{

	for(std::vector<pBrick>::iterator it=m_bricks.begin(); it!=m_bricks.end(); ++it)
	{
		(*it)->show( rndr );
	}
	if(m_movingLeft)
	{
		m_piece->move(-m_brick_sz,0);
		if(isCollision())
		{
			m_piece->move(m_brick_sz,0);
		}
	}
	if(m_movingRight)
	{
		m_piece->move(m_brick_sz,0);
		if(isCollision())
		{
			m_piece->move(-m_brick_sz,0);
		}
	}
	m_piece->show( rndr );
}

bool Game::isCollision()
{
	
		pBrick* newBricks=m_piece->getBricks();
		for(int i = 0; i<TETRIMINO_SIZE; ++i)
		{
			pBrick current=newBricks[i];
			SDL_Point pos=current->getPos();
			if(pos.x<0 || pos.x+m_brick_sz>m_width || pos.y+m_brick_sz>m_height)
			{
				return true;
			}
			else
			{
				for(std::vector<pBrick>::iterator it=m_bricks.begin(); it!=m_bricks.end(); ++it)
				{
					SDL_Point fixedPos=(*it)->getPos();
					if(pos.x==fixedPos.x && pos.y==fixedPos.y)
					{
						return true;
					}
				}
			}
		}
		return false;
}

void Game::step()
{
	if(!m_stopped)
	{
		m_piece->move(0,m_brick_sz);
		if(isCollision())
		{
			m_piece->move(0,-m_brick_sz);
			pBrick* newBricks=m_piece->getBricks();
			for(int i = 0; i<TETRIMINO_SIZE; ++i)
			{
				pBrick current=newBricks[i];
				m_bricks.push_back(current);
			}
			newPiece();
			if(isCollision())
			{
				SDL_Log("Game over!");
				m_stopped=true;
			}
			//SDL_Log("m_bricks has %lu elements\n",m_bricks.size());
		}
	}
}

