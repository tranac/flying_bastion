#include "airsoldier.h"

//check position
AirSoldier::AirSoldier(QPixmap* pic, QPixmap* pic2) : Item(645,10,-1,0,pic)
{
	pic2_ = pic2;
	setPixmap(*pic_);
	moves_ = 0;
}

AirSoldier::~AirSoldier()
{

}

void AirSoldier::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
		
	//if across the screen, change vy
	if(x_ ==  300)
		vy_ = 1;
		
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
	
	moves_++;
}

