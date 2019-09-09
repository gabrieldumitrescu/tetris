#include "Tetrimino.h"

Tetrimino::Tetrimino(int x, int y,int brick_sz,Tetrimino_t type):
m_type(type)
{
	m_pos={x,y};
	Color orange={0xFF,0xA5,0x00,0xFF};
	for(int i=0; i<TETRIMINO_SIZE;i++){
		pBrick oneBrick=std::make_shared<Brick>(x,y,brick_sz,brick_sz,orange);
		m_bricks[i]=oneBrick;
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

