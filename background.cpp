#include "background.h"

/**
@param x initial x-coordinate
@param l1 pointer to level one image
@param l2 pointer to level two image
@param l3 pointer to level three image

Creates a scrolling Background object. Two will be created for the background. Image will change for each level. Image initialized to l1_.
*/
Background::Background(int x, QPixmap* l1, QPixmap* l2, QPixmap* l3)
{
	x_ = x;
	y_ =-10;
	setPos(x_,y_);
	l1_ = l1;
	l2_ = l2;
	l3_ = l3;
	setPixmap(*l1_);
}

/**
Nothing needs to be deleted.
*/
Background::~Background()
{
}

/**
Moves the background image one pixel to the left.
*/
void Background::move()
{
	//if at the end of the screen, wrap around
	if(x_ == -1000)
	{
		x_ = 650;
	}
	else //else move one pixel
	{
		x_ = x_ - 1;
	}
	
	setPos(x_,y_);
}

/**
@param l Level to change image to.
Changes background image for each level.
*/
void Background::setImage(int l)
{
  if(l == 1)
    setPixmap(*l1_);
  else if(l == 2)
    setPixmap(*l2_);
  else
    setPixmap(*l3_);
}
