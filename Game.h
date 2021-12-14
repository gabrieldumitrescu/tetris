#include "Tetrimino.h"
#include <SDL2/SDL.h>
#include <vector>

#ifndef GAME_H
#define GAME_H


class Game{
	protected:
		std::vector<pBrick> m_bricks;
		int m_width, m_height, m_brick_sz;
		pTetrimino m_piece;
		bool m_stopped, m_movingLeft, m_movingRight;
		public:
		Game(int width, int height, int brick_sz);
		void newPiece();
		void show(SDL_Renderer*);
		bool isCollision();
		void step();
		bool isStopped() const { return m_stopped; }
		void movePieceLeft(bool move){ m_movingLeft=move; }
		void movePieceRight(bool move) { m_movingRight=move; }		
		void rotatePiece() { m_piece->rotate(); }
};

#endif //GAME_H
