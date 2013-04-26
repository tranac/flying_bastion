#include "aquatank.h"

//check position
Aquatank::Aquatank(int y, int vx) : Item(350,y,vx,0)
{
	pic_ = new QPixmap("images/aquatank.png","png");
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

