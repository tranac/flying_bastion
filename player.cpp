#include "player.h"

/**
Creates a Player object. Initial coordinates are always (50,125).
*/
Player::Player()
{
	x_ = 50;
	y_ = 125;
	setPos(x_,y_);
	pic_ = new QPixmap("images/wizard1.png","png");
	pic2_ = new QPixmap("images/wizard2.png","png");
	setPixmap(*pic_);
}

/**
Deletes dynamically-allocated Pixmap images.
*/
Player::~Player()
{
	delete pic_;
	delete pic2_;
}

/**
@param x tells the player to move up or down. 0 if the mouse is pressed, 1 if not.

If x is 1, the player moves 2 pixels downwards. If it's 0, it moves 2 pixels upwards.
*/
void Player::move(int x)
{
	//falling is mouse isn't clicked
	if(x)
	{
	    y_ = y_ + 2;
		setPixmap(*pic2_);
	}
	else //else negative velocity
	{
		y_ = y_ - 2;
		setPixmap(*pic_);
	}
	
	setPos(x_,y_);
}
