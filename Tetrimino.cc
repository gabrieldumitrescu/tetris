#include "Tetrimino.h"

Tetrimino::Tetrimino(int x, int y,int brick_sz,Tetrimino_t type):
m_type(type)
{
	m_pos={x,y};
	switch(type)
	{
		case I_TETRIMINO:
			makeIPiece(brick_sz);
			break;
		case J_TETRIMINO:
			makeJPiece(brick_sz);
			break;
		case L_TETRIMINO:
			makeLPiece(brick_sz);
			break;
		case O_TETRIMINO:
			makeOPiece(brick_sz);
			break;
		case S_TETRIMINO:
			makeSPiece(brick_sz);
			break;
		case T_TETRIMINO:
			makeTPiece(brick_sz);
			break;
		case Z_TETRIMINO:
			makeZPiece(brick_sz);
			break;
	}
}

void Tetrimino::makeIPiece(int brick_sz)
{
	Color pieceCol={0x00,0xFF,0xFF,0xFF};
	m_pos.x-=brick_sz;
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		x+=brick_sz;
	}
}


void Tetrimino::makeJPiece(int brick_sz)
{
	Color pieceCol={0x00,0x00,0xFF,0xFF};
	m_pos.x-=brick_sz;
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		if(i==TETRIMINO_SIZE-2)
		{
			y-=brick_sz;
			x+=brick_sz;
		}
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		if(i<2)
		{
			y+=brick_sz;
		}
		else
		{
			x+=brick_sz;
		}
	}
}


void Tetrimino::makeLPiece(int brick_sz)
{
	Color pieceCol={0xFF,0xA5,0x00,0xFF};
	m_pos.x+=brick_sz;
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{

		if(i==TETRIMINO_SIZE-2)
		{
			x-=2*brick_sz;
			y-=brick_sz;
		}
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		if(i<2)
		{
			y+=brick_sz;
		}
		else
		{
			x+=brick_sz;
		}
	}
}


void Tetrimino::makeTPiece(int brick_sz)
{
	Color pieceCol={0xFF,0x00,0xFF,0xFF};
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		if(i==TETRIMINO_SIZE-1)
		{
			x-=2*brick_sz;
			y+=brick_sz;
		}
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		x+=brick_sz;
	}
}


void Tetrimino::makeOPiece(int brick_sz)
{
	Color pieceCol={0xFF,0xFF,0x00,0xFF};
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		if(i==TETRIMINO_SIZE-2)
		{
			x-=2*brick_sz;
			y+=brick_sz;
		}
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		x+=brick_sz;
	}
}


void Tetrimino::makeZPiece(int brick_sz)
{
	Color pieceCol={0xFF,0x00,0x00,0xFF};
	m_pos.x-=brick_sz;
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		if(i==TETRIMINO_SIZE-2)
		{
			x-=brick_sz;
			y+=brick_sz;
		}
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		x+=brick_sz;
	}
}


void Tetrimino::makeSPiece(int brick_sz)
{
	Color pieceCol={0x00,0xFF,0x00,0xFF};
	int x=m_pos.x,y=m_pos.y;
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		if(i==TETRIMINO_SIZE-2)
		{
			x-=3*brick_sz;
			y+=brick_sz;
		}
		m_bricks[i]=std::make_shared<Brick>(x,y,brick_sz,brick_sz,pieceCol);
		x+=brick_sz;
	}
}

void Tetrimino::show(SDL_Renderer* rndr) const
{
	for(int i=0; i<TETRIMINO_SIZE;i++){
		m_bricks[i]->show( rndr );
	}
}

void Tetrimino::move(int x, int y)
{
	m_pos={m_pos.x + x, m_pos.y +y};
	for(int i=0; i<TETRIMINO_SIZE;i++){
		m_bricks[i]->move(x,y);
	}
}

