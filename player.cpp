#include "player.h"

Player::Player()
{
	x_ = 50;
	y_ = 125;
	setPos(x_,y_);
	pic_ = new QPixmap("images/aquatank.png","png");
	pic2_ = new QPixmap("images/player2.png","png");
	setPixmap(*pic_);
	f = true;
}

Player::~Player()
{
//	delete pic_;
}

void Player::move(int x)
{
	//if falling, positive velocity
	if(x)
		y_ = y_ + 1;
	else //else negative velocity
		y_ = y_ - 1;
	
	setPos(x_,y_);
}

void Player::flash()
{
	if(f)
	{
		setPixmap(*pic2_);
		f = false;
	}
	else
	{
		setPixmap(*pic_);
		f = true;
	}
}
