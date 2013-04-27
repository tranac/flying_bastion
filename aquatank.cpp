#include "aquatank.h"
#include "main.h"

/**
@param y y-coordinate of the Aquatank relative to the scene; randomized in Main
@param vx velocity in x-direction
@param pic pointer to the item's first image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 645, the right boundary of the game. vy is always 0. Aquatank only has one image, so pic2_ is set to NULL.
*/
Aquatank::Aquatank(int y, int vx, QPixmap* pic, Player* p, MainWindow* main) : Item(645,y,vx,0,pic,NULL,p,main)
{
}

/**
Deconstructor. Nothing is dynamically-allocated.
*/
Aquatank::~Aquatank()
{
}

/** 
Moves the Aquatank in the intended direction. Aquatank always moves across the screen in a horizontal line at a constant pace.
*/
void Aquatank::move()
{
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

/**
Checks if the Aquatank has collided with the player. If it has, main_->loseLife() is called.
*/
void Aquatank::collide()
{
	if((x_ >= p_->getX()+80) && (x_ <= p_->getX()+83) && (y_ >= p_->getY()-5) && (y_ <= p_->getY() + 82))
		main_->setLife(0);
}
