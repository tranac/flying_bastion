#include "tornadostep.h"
#include "main.h"

TornadoStep::TornadoStep(int y, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(645,y,-1,1,pic,pic2,p,main)
{
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

void TornadoStep::collide()
{
	if((x_ == p_->getX()+83) && (y_ >= p_->getY()) && (y_ <= p_->getY() +  82))
		main_->gainPoints();
}

