#include "player.h"

Player::Player()
{
	x_ = 50;
	y_ = 125;
	setPos(x_,y_);
	pic_ = new QPixmap("images/wizard1.png","png");
	pic2_ = new QPixmap("images/wizard2.png","png");
	setPixmap(*pic_);
	f = true;
}

Player::~Player()
{
//	delete pic_;
}

void Player::move(int x)
{
	//falling is mouse isn't clicked
	if(x)
	{
		y_ = y_ + 1;
		setPixmap(*pic2_);
	}
	else //else negative velocity
	{
		y_ = y_ - 1;
		setPixmap(*pic_);
	}
	
	setPos(x_,y_);
}

void Player::flash()
{
	setVisible(f);
	
	if(f)
		f = false;
	else
		f = true;
}
