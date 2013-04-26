#include "item.h"

Item::Item(int x, int y, int vx, int vy, QPixmap* pic)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	vx_ = vx;
	vy_ = vy;
	pic_ = pic;
}

Item::~Item()
{
}
