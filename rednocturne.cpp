#include "rednocturne.h"

//check position
RedNocturne::RedNocturne(int y, int vx, QPixmap* pic, QPixmap* pic2) : Item(645,y,vx,0,pic)
{
	pic2_ = pic2;
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

