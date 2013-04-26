#include "whitemushroom.h"
#include <iostream>

//check position
WhiteMushroom::WhiteMushroom(int y, Player* p, QPixmap* pic, QPixmap* pic2) : Item(645,y,-1,0,pic)
{
	pic2_ = pic2;
	setPixmap(*pic_);
	moves_ = 0;
	p_ = p;
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
	if((x_ > 150) && (y_ == p_->getY()))
	{
		if(y_ >= 50)
			y_ = y_-50;
		else
			y_ = y_+50;
	}
	else
		y_ = y_ + vy_;

	//change xy coordinates
	x_ = x_ + vx_;
	setPos(x_,y_);
	
	moves_++;
}

