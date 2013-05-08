#include "wyvern.h"
#include "main.h"

/**
@param pic pointer to the item's first image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 680. Initial y is always 300, at the bottom of the screen. vx is -2 and vy is initially 0. It will be changed in move().
*/
Wyvern::Wyvern(QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(680,250,-2,0,pic,pic2,p,main)
{
	ct = 0;
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
Wyvern::~Wyvern()
{
}

/** 
Moves the Wyvern in the intended direction. It starts moving in a straight horizontal line. After 80 pixels, it moves up 40 pixels, travels in a straight line for 10 more pixels, and continues.

The image alternates for each move.
*/
void Wyvern::move()
{
	ct++;
	
	if(ct == 100)
	{
		setPixmap(*pic2_);
		vy_ = -1;
	}
		
	if(ct == 150)
	{
		setPixmap(*pic_);
		vy_ = 0;
		ct = 0;
	}
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

/**
Checks if the Wyvern has collided with the player. If it has, main_->loseLife() is called.
*/
void Wyvern::collide()
{
	if(QGraphicsItem::collidesWithItem(p_,Qt::IntersectsItemShape))
		main_->loseLife();
}
