#include "tornadostep.h"
#include "main.h"

#include <iostream>

/**
@param y y-coordinate of the TornadoStep relative to the scene; randomized in Main
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 645, the right boundary of the game. vx is always -1 (1 in the left direction) and vy is initially 1. It will be changed in move().
*/
TornadoStep::TornadoStep(int y, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(645,y,-1,1,pic,pic2,p,main)
{
	c_ = 0;
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
TornadoStep::~TornadoStep()
{
}

/** 
Moves the TornadoStep in the intended direction. TornadoStep moves diagonally up and down over a range of 100 pixels unless it is about to hit a boundary.

The image alternates for each move.
*/
void TornadoStep::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	
	//if reached boundary, change direction
	if((c_ == 100) || (y_ == 330) || !y_)
	{
		vy_ = -vy_;
		c_ = 0;
	}
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
	
	c_++;
}

/**
Checks if the TornadoStep has collided with the player. If it has, main_->gainPoints() is called.
*/
void TornadoStep::collide()
{
	if((x_ >= p_->getX()+80) && (x_ <= p_->getX()+83) && (y_ >= p_->getY()-5) && (y_ <= p_->getY() + 82))
	{
		main_->gainPoints();
	}
}

