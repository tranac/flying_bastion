#include "item.h"

Item::Item(int x, int y, int vx, int vy)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	vx_ = vx;
	vy_ = vy;
}

Item::~Item()
{
}
