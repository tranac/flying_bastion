#include "airsoldier.h"
#include "main.h"

/**
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 644, the right boundary of the game. Initial v is always 10, at the top of the screen. vx is -1 and vy is initially 0. It will be changed in move().
*/
AirSoldier::AirSoldier(QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(644,10,-2,0,pic,pic2,p,main)
{
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
AirSoldier::~AirSoldier()
{
}

/** 
Moves the AirSoldier in the intended direction. It starts moving in a straight horizontal line. At the halfway point, it dives down diagonally.

The image alternates for each move.
*/
void AirSoldier::move()
{
	//every other move, change image
	if(x_ % 4)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
		
	//if across the screen, change vy
	if(x_ <= 225)
		vy_ = 1;
		
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

/**
Checks if the AirSoldier has collided with the player. If it has, main_->loseLife() is called.
*/
void AirSoldier::collide()
{
	if((x_ >= p_->getX()+80) && (x_ <= p_->getX()+83) && (y_ >= p_->getY()-5) && (y_ <= p_->getY() + 82))
	  {
		main_->loseLife();
	  }
}
