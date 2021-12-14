#include "Brick.h"

Brick::Brick(int x, int y, int w, int h, Color c, bool renderOutline):
		m_renderOutline(renderOutline),m_color(c)
{
	m_rect = {x,y,w,h}; 
}

void Brick::show(SDL_Renderer* rndr)
{
	//if(m_rect.x < 0 || m_rect.y < 0 || m_rect.w < 0 || m_rect.h < 0)
	//	return;	
	SDL_SetRenderDrawColor( rndr, m_color.r, m_color.g, m_color.b, m_color.a );				
	SDL_RenderFillRect( rndr, &m_rect);
	if(m_renderOutline)
	{
		SDL_SetRenderDrawColor( rndr, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE );
		SDL_RenderDrawRect( rndr, &m_rect);	
	}
}

void Brick::setColor(Color c)
{
	m_color = c;
}

SDL_Point Brick::getCenterPos() const
{
	SDL_Point pos;
	pos.x = m_rect.x + m_rect.w * 0.5;
	pos.y = m_rect.y + m_rect.h * 0.5;
	return pos;
}

SDL_Point Brick::getPos() const
{
	SDL_Point pos;
	pos.x = m_rect.x;
	pos.y = m_rect.y;
	return pos;
}

void Brick::setPos(int x, int y)
{
	m_rect.x = x;
	m_rect.y = y;
}


void Brick::move(int x, int y)
{
	m_rect.x += x;
	m_rect.y += y;
}

