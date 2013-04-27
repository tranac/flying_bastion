#include "gargoyle.h"
#include "main.h"

/**
@param y y-coordinate of the Gargoyle relative to the scene; player's current y-position
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 645, the right boundary of the game. vx is always -1 and vy is always 0.
*/
Gargoyle::Gargoyle(int y, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(645,y,-1,0,pic,pic2,p,main)
{
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
Gargoyle::~Gargoyle()
{
}

/** 
Moves the Gargoyle in the intended direction. For the first third of the screen, it mirrors the player's y-coordinate. After that it travels in a straight horizontal line.

The image stays as one image as it mirrors the player and changes to another once it starts travelling in a straight horizontal line.
*/
void Gargoyle::move()
{
	//if inline with player & not a third of the way across screen, match player y-coordinate
	if((x_ > 400))
	{
		y_ = p_->getY();
	}
	else
	{
		y_ = y_ + vy_;
		setPixmap(*pic2_);
	}
	//change xy coordinates
	x_ = x_ + vx_;
	setPos(x_,y_);
}

/**
Checks if the Gargoyle has collided with the player. If it has, main_->loseLife() is called.
*/
void Gargoyle::collide()
{
	if((x_ == p_->getX()+83) && (y_ >= p_->getY()) && (y_ <= p_->getY() +  82))
		main_->loseLife();
}
