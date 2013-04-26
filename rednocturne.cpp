#include "rednocturne.h"

//check position
RedNocturne::RedNocturne(int y, int vx) : Item(350,y,vx,0)
{
	pic_ = new QPixmap("images/rednocturne1.png","png");
	pic2_ = new QPixmap("images/rednocturne2.png","png");
	setPixmap(*pic_);
}

RedNocturne::~RedNocturne()
{

}

void RedNocturne::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}
