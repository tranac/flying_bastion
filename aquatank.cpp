#include "aquatank.h"

//check position
Aquatank::Aquatank(int y, int vx, QPixmap* pic) : Item(350,y,vx,0,pic)
{
	setPixmap(*pic_);
}

Aquatank::~Aquatank()
{

}

void Aquatank::move()
{
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

