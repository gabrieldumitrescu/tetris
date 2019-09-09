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
		bool m_stopped;
		public:
		Game(int width, int height, int brick_sz);
		void show(SDL_Renderer*);
		bool isCollision();
		void step();
		bool isStopped() const { return m_stopped; }
		

};

#endif //GAME_H
