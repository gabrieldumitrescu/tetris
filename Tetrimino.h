#include "Brick.h"
#include <SDL2/SDL.h>
#include <memory>

#ifndef TETRIMINO_H
#define TETRIMINO_H

#define TETRIMINO_SIZE 4

enum Tetrimino_t{
	I_TETRIMINO,
	J_TETRIMINO,
	L_TETRIMINO,
	O_TETRIMINO,
	S_TETRIMINO,
	T_TETRIMINO,
	Z_TETRIMINO,
	TETRIMINO_T_END
};

const int I_TETRIMINO_NUM_VERSIONS=2;
const int I_TETRIMINO_VER[I_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	0,2,1,2,2,2,3,2,
	2,0,2,1,2,2,2,3
};

const int O_TETRIMINO_NUM_VERSIONS=1;
const int O_TETRIMINO_VER[O_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	1,1,2,1,1,2,2,2
};

const int L_TETRIMINO_NUM_VERSIONS=4;
const int L_TETRIMINO_VER[L_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	0,1,1,1,2,1,0,2,
	0,0,1,0,1,1,1,2,
	0,1,1,1,2,1,2,0,
	1,0,1,1,1,2,2,2
};

const int J_TETRIMINO_NUM_VERSIONS=4;
const int J_TETRIMINO_VER[J_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	0,1,1,1,2,1,2,2,
	1,0,1,1,1,2,0,2,
	0,0,0,1,1,1,2,1,
	1,0,1,1,1,2,2,0
};

const int S_TETRIMINO_NUM_VERSIONS=2;
const int S_TETRIMINO_VER[S_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	0,2,1,2,1,1,2,1,
	1,0,1,1,2,1,2,2
};

const int T_TETRIMINO_NUM_VERSIONS=4;
const int T_TETRIMINO_VER[T_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	0,1,1,1,2,1,1,2,
	0,1,1,1,1,0,1,2,
	0,1,1,1,2,1,1,0,
	1,0,1,1,1,2,2,1
};

const int Z_TETRIMINO_NUM_VERSIONS=2;
const int Z_TETRIMINO_VER[Z_TETRIMINO_NUM_VERSIONS * TETRIMINO_SIZE * 2] = {
	0,1,1,1,1,2,2,2,
	1,1,1,2,2,1,2,0
};

class Tetrimino;
typedef std::shared_ptr<Tetrimino> pTetrimino;

class Tetrimino{
	protected:
		pBrick  m_bricks[TETRIMINO_SIZE];
		SDL_Point m_pos;
		Tetrimino_t m_type;

		//size of the bricks, number of rotations of curent tetrimino type
		//and current version(aka rotation) of the current type
		int m_sz, m_num_versions, m_version;


		//points to the relative position data of the current tetrimino type and for the current version
		int* m_type_start, *m_ver_start;

		Color m_color;

		//update the m_ver_pos pointer according to the current version of tetrimino type
		//must call when we change m_version
		void updateBricks();

		void makeIPiece(int version=0);
		void makeJPiece(int version=0);
		void makeLPiece(int version=0);
		void makeOPiece(int version=0);
		void makeSPiece(int version=0);
		void makeTPiece(int version=0);
		void makeZPiece(int version=0);

    void makeBricks();
		void placeBricks();
	public:
		Tetrimino(int x, int y,int brick_sz,Tetrimino_t type);
		pBrick* getBricks() {return m_bricks; }
		void show(SDL_Renderer*) const;
		void move(int x, int y);
		Tetrimino_t getType() const { return m_type; }
		SDL_Point getPos() const {return m_pos; }
		void rotate(bool forward=true);
};

#endif //TETRIMINO_H
