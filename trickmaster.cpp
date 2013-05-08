#include "trickmaster.h"
#include "main.h"

/**
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 5 and Initial y is always 200, the bottom-left corner of the screen. Object does not move until after it's been on the screen for 250 timeouts;
*/
Trickmaster::Trickmaster(QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(5,200,0,0,pic,pic2,p,main)
{
	moves = 0;
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
Trickmaster::~Trickmaster()
{
}

/** 
Moves the Trickmaster in the intended direction. It stays stationary at first and after 250 moves, moves off the screen.

The image changes to an upright Trickmaster when they can kill you.
*/
void Trickmaster::move()
{
	//if it's been 100 clicks, move trickmaster up and make it collidable
	if(moves == 100)
		setPixmap(*pic2_);
	//checks if time to move trickmaster out of screen
	else if(moves == 250)
		vx_ = -2;
		
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
	
	//increase moves
	moves++;
}

/**
Checks if the Trickmaster has collided with the player. Only checks collision if Trickmaster is in "stage two" and able to be collided with If it has, main_->setLife() is called and set to 0.
*/
void Trickmaster::collide()
{
	if(moves > 100)
	{
		if(QGraphicsItem::collidesWithItem(p_,Qt::IntersectsItemShape))
			main_->setLife(0);
	}
}
