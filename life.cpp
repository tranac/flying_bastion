#include "life.h"

Life::Life(int x, int y, QPixmap* pic)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	pic_ = pic;
	setPixmap(*pic_);
}

Life::~Life()
{

}
