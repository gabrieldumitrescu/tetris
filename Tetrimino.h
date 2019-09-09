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
	Z_TETRIMINO
};

class Tetrimino;
typedef std::shared_ptr<Tetrimino> pTetrimino;

class Tetrimino{
	protected:
		pBrick  m_bricks[TETRIMINO_SIZE];
		SDL_Point m_pos;
		Tetrimino_t m_type;	
		void makeIPiece(int brick_sz);
		void makeJPiece(int brick_sz);
		void makeLPiece(int brick_sz);
		void makeOPiece(int brick_sz);
		void makeSPiece(int brick_sz);
		void makeTPiece(int brick_sz);
		void makeZPiece(int brick_sz);
	public:
		Tetrimino(int x, int y, int brick_sz,Tetrimino_t type);
		pBrick* getBricks() {return m_bricks; }
		void show(SDL_Renderer*) const;
		void move(int x, int y);
		Tetrimino_t getType() const { return m_type; }
		SDL_Point getPos() const {return m_pos; }
};

#endif //TETRIMINO_H
