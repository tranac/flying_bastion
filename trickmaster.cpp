#include "trickmaster.h"
#include "main.h"

/**
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 5 and Initial y is always 300, the bottom-left corner of the screen. Object does not move until after it's been on the screen for 50 handleTimer();
*/
Trickmaster::Trickmaster(QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(5,300,0,0,pic,pic2,p,main)
{
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
Trickmaster::~Trickmaster()
{
}

/** 
Moves the Trickmaster in the intended direction. It starts moving in a straight horizontal line. At the halfway point, it dives down diagonally.

The image alternates for each move.
*/
void Trickmaster::move()
{
	//if it's been 10 clicks, move trickmaster up and make it collidable
	if(moves == 10)
		setPixmap(*pic2_);
	//checks if time to move trickmaster out of screen
	else if(moves == 50)
		vx_ = -2;
		
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
	
	//increase moves
	moves++;
}

/**
Checks if the Trickmaster has collided with the player. Only checks collision if Trickmaster is in "stage two" and able to be collided with If it has, main_->setLife() is called.
*/
void Trickmaster::collide()
{
	if(moves > 10)
	{
		if(QGraphicsItem::collidesWithItem(p_,Qt::IntersectsItemShape))
			main_->setLife(0);
	}
}
