#include "whitemushroom.h"
#include "main.h"

WhiteMushroom::WhiteMushroom(int y, Player* p, QPixmap* pic, QPixmap* pic2, MainWindow* main) : Item(645,y,-1,0,pic,pic2,p,main)
{
}

WhiteMushroom::~WhiteMushroom()
{
}

void WhiteMushroom::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	
	//if inline with player & not halfway across screen, teleport up or down
	if((x_ > 350) && (y_ >= p_->getY()) && (y_ <= p_->getY()+82))
	{
		if(y_ <= 50)
			y_ = y_+50;
		else if(y_ >= 300) 
			y_ = y_-50;
		else
		{
			int rand = std::rand() % 2;
			if(rand)
				y_ = y_+50;
			else
				y_ = y_-50;
		}
	}
	else
		y_ = y_ + vy_;

	//change xy coordinates
	x_ = x_ + vx_;
	setPos(x_,y_);
}

void WhiteMushroom::collide()
{
	if((x_ == p_->getX()+83) && (y_ >= p_->getY()) && (y_ <= p_->getY()+82))
		main_->gainLife();
}
