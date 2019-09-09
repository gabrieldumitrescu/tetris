/* One sqare tetris brick on screen */

#ifndef BRICK_H
#define BRICK_H

#include <SDL2/SDL.h>
#include <vector>
#include <memory>

struct Color
{
	Uint8 r,g,b,a;
};

class Brick;
typedef std::shared_ptr<Brick> pBrick;

class Brick
{
	SDL_Rect m_rect;
	bool m_renderOutline;
	Color m_color;
public:
	Brick(int x, int y, int w, int h, Color c,  bool renderOutline=true);
	void show(SDL_Renderer* rndr);	
	void setColor(Color c);
	SDL_Point getPos() const;
	SDL_Point getCenterPos() const;
	void setPos(int,int);
	void move(int, int);
};



#endif //CELL_H
