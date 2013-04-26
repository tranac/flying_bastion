#include "player.h"

Player::Player()
{
	x_ = 50;
	y_ = 125;
	setPos(x_,y_);
	pic_ = new QPixmap("images/aquatank.png","png");
	setPixmap(*pic_);
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

void Player::collidesWith(Item* item)
{
	
}
