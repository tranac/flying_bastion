#include "background.h"

/**
Creates a Background object. Initial coordinates are always (50,125).
*/
Background::Background(int x, QPixmap* pic)
{
	x_ = x;
	y_ =-10;
	setPos(x_,y_);
	pic_ = pic;
	setPixmap(*pic_);
}

/**
Deletes dynamically-allocated Pixmap images.
*/
Background::~Background()
{
	delete pic_;
}

/**

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
