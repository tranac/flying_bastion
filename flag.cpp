#include "flag.h"

Flag::Flag(int x, int y, QPixmap* pic)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	setPixmap(*pic);
	pic_ = pic;
}

Flag::~Flag()
{
}
