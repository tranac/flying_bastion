#include "whitemushroom.h"
#include "main.h"

/**
@param y y-coordinate of the WhiteMushroom relative to the scene; randomized in Main
@param p pointer to the player of the game
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 644, the right boundary of the game. vx is always -1 (1 in the left direction) and vy is 0.
*/
WhiteMushroom::WhiteMushroom(int y, Player* p, QPixmap* pic, QPixmap* pic2, MainWindow* main) : Item(644,y,-2,0,pic,pic2,p,main)
{
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
WhiteMushroom::~WhiteMushroom()
{
}

/** 
Moves WhiteMushroom in the intended direction. WhiteMushroom initally moves in a straight horizontal line. Before it reaches the halfway point, if x_ matches p_->getX(), then the WhiteMushroom teloports 50 pixels up or 50 pixels down. Direction is random unless a boundary is near.

The image alternates for each move.
*/
void WhiteMushroom::move()
{
	//every other move, change image
	if(x_ % 12)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	
	//if inline with player & not halfway across screen, teleport up or down
	if((x_ > 350) && (y_ >= p_->getY()) && (y_ <= p_->getY()+85))
	{
		if(y_ <= 50)
			y_ = y_+50;
		else if(y_ >= 275) 
			y_ = y_-50;
		else
		{
			int rand = std::rand() % 2;
			if(rand)
				y_ = y_+50;
			else
				y_ = y_-50;
		}
	}
	else
		y_ = y_ + vy_;

	//change xy coordinates
	x_ = x_ + vx_;
	setPos(x_,y_);
}

/**
Checks if the WhiteMushroom has collided with the player. If it has, main_->gainLife() is called.
*/
void WhiteMushroom::collide()
{
	if((x_ == p_->getX()+83) && (y_ >= p_->getY()) && (y_ <= p_->getY()+82))
//	if(y_ <= (p_->getY()+85) && p_->getY() >= (y_+52) && x_ <= (p_->getX()+80) && p_->getX() >= (x_+35))
		main_->gainLife();
}
