#include "aquatank.h"
#include "main.h"

/**
@param y y-coordinate of the Aquatank relative to the scene; randomized in Main
@param pic pointer to the item's first image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

An Item is created with these coordinates. x is always 644, the right boundary of the game. vx is always -3 and vy is always 0. Aquatank only has one image, so pic2_ is set to NULL.
*/
Aquatank::Aquatank(int y, QPixmap* pic, Player* p, MainWindow* main) : Item(644,y,-3,0,pic,NULL,p,main)
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
	if(QGraphicsItem::collidesWithItem(p_,Qt::IntersectsItemShape))
		main_->setLife(0);
}
