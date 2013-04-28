#include "rednocturne.h"
#include "main.h"

/**
@param y y-coordinate of the RedNocturne relative to the scene; randomized in Main
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 644, the right boundary of the game. vy is always -3 and vy is always 0.
*/
RedNocturne::RedNocturne(int y, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(644,y,-3,0,pic,pic2,p,main)
{
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
RedNocturne::~RedNocturne()
{
}

/** 
Moves the RedNocturne in the intended direction. RedNocturne always moves across the screen in a horizontal line at a constant pace.

The image alternates for each move.
*/
void RedNocturne::move()
{
	//every other move, change image
	if(x_ % 4)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

/**
Checks if the RedNocturne has collided with the player. If it has, main_->loseLife() is called.
*/
void RedNocturne::collide()
{
	if((x_ >= p_->getX()+80) && (x_ <= p_->getX()+83) && (y_ >= p_->getY()) && (y_ <= p_->getY() +  82))
		main_->loseLife();
}
