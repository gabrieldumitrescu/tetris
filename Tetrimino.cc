#include "Tetrimino.h"

Tetrimino::Tetrimino(int x, int y,int brick_sz,Tetrimino_t type):
	m_type(type),m_sz(brick_sz)
{
	m_pos={x,y};
	switch(type)
	{
		case I_TETRIMINO:
			makeIPiece();
			break;
		case J_TETRIMINO:
			makeJPiece();
			break;
		case L_TETRIMINO:
			makeLPiece();
			break;
		case O_TETRIMINO:
			makeOPiece();
			break;
		case S_TETRIMINO:
			makeSPiece();
			break;
		case T_TETRIMINO:
			makeTPiece();
			break;
		case Z_TETRIMINO:
			makeZPiece();
			break;
	}
}


void Tetrimino::updateBricks(){

	int offset=m_version * 2 * TETRIMINO_SIZE;
	m_ver_start=m_type_start + offset;
	placeBricks();
}

void Tetrimino::makeBricks() 
{
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		m_bricks[i]=std::make_shared<Brick>(0,0,m_sz,m_sz,m_color);
	}
}

void Tetrimino::placeBricks() 
{
	for(int i=0; i<TETRIMINO_SIZE;i++)
	{
		int x=m_ver_start[i * 2];
		int y=m_ver_start[i * 2 + 1];
		m_bricks[i]->setPos(m_pos.x + x * m_sz,m_pos.y + y * m_sz);
	}
}


void Tetrimino::makeIPiece(int version)
{
	m_color={0x00,0xFF,0xFF,0xFF};
	m_type_start=(int*) I_TETRIMINO_VER;
	m_num_versions=I_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=m_sz;
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
}


void Tetrimino::makeJPiece(int version)
{
	m_color={0x00,0x00,0xFF,0xFF};
	m_type_start=(int*) J_TETRIMINO_VER;
	m_num_versions=J_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=m_sz;
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
}


void Tetrimino::makeLPiece(int version)
{
	m_color={0xFF,0xA5,0x00,0xFF};
	m_type_start=(int*) L_TETRIMINO_VER;
	m_num_versions=L_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=m_sz;
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
}


void Tetrimino::makeTPiece(int version)
{
	m_color={0xFF,0x00,0xFF,0xFF};
	m_type_start=(int*) T_TETRIMINO_VER;
	m_num_versions=T_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=m_sz;
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
}


void Tetrimino::makeOPiece(int version)
{
	m_color={0xFF,0xFF,0x00,0xFF};
	m_type_start=(int*) O_TETRIMINO_VER;
	m_num_versions=O_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=(m_sz);
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
}


void Tetrimino::makeZPiece(int version)
{
	m_color={0xFF,0x00,0x00,0xFF};
	m_type_start=(int*) Z_TETRIMINO_VER;
	m_num_versions=Z_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=m_sz;
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
}


void Tetrimino::makeSPiece(int version)
{
	m_color={0x00,0xFF,0x00,0xFF};
	m_type_start=(int*) S_TETRIMINO_VER;
	m_num_versions=S_TETRIMINO_NUM_VERSIONS;
	m_version=version<m_num_versions ? version : 0;
	m_pos.x-=m_sz;
	m_pos.y-=(2*m_sz);
	makeBricks();
	updateBricks();
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

void Tetrimino::rotate(bool forward)
{
	if (forward) {
		m_version++;
		if(m_version>=m_num_versions) m_version=0;
	}
	else {
		m_version--;
		if(m_version<0) m_version=m_num_versions-1;
	}
	updateBricks();
}

