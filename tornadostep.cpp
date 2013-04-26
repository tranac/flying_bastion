#include "tornadostep.h"

TornadoStep::TornadoStep(int y, QPixmap* pic, QPixmap* pic2) : Item(645,y,-1,1,pic)
{
	pic2_ = pic2;
	setPixmap(*pic_);
	c_ = 0;
}

TornadoStep::~TornadoStep()
{

}

void TornadoStep::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	
	//if reached boundary, change direction
	if((c_ == 100) || (y_ == 330) || !y_)
	{
		vy_ = -vy_;
		c_ = 0;
	}
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
	
	c_++;
}

