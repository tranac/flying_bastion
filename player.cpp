#include "player.h"
#include "main.h"

/**
Creates a Player object. Initial coordinates are always (50,125).
*/
Player::Player(MainWindow* main)
{
	x_ = 50;
	y_ = 125;
	setPos(x_,y_);
	pic_ = new QPixmap("images/wizard1.png","png");
	pic2_ = new QPixmap("images/wizard2.png","png");
	setPixmap(*pic_);
	main_ = main;
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
	//if a player is at the boundaries, cause them to fall/ascend 2 pixels
	if(y_ >= 300)
		y_ = y_ - 5;
	else if(y_ <= 0)
		y_ = y_ + 5;

	else
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
	}
	
	setPos(x_,y_);
}

/**
Checks if the player collides with the boundaries.
*/
void Player::collide()
{
	if(y_ <= 0 || y_ >= 300)
		main_->loseLife();
}
