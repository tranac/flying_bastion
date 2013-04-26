#include "item.h"
#include "main.h"

Item::Item(int x, int y, int vx, int vy, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	vx_ = vx;
	vy_ = vy;
	pic_ = pic;
	pic2_ = pic2;
	setPixmap(*pic_);
	p_ = p;
	main_ = main;
}

Item::~Item()
{

}

bool Item::collide()
{
	if((x_ == p_->getX()) && (y_ >= p_->getY()) && (y_ <= p_->getY() +  82))
		return true;

	return false;
}
