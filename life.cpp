#include "life.h"

/**
@param x initial x-coordinate of Life relative to the scene
@param y initial y-coordinate of Life relative to the scene
@para pic pointer to Life's image
*/
Life::Life(int x, int y, QPixmap* pic)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	pic_ = pic;
	setPixmap(*pic_);
}

/**
Deconstructor. Nothing dynamically allocated.
*/
Life::~Life()
{
}
