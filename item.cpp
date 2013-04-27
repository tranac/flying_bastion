#include "item.h"
#include "main.h"

/** Default Item constructor 

@param x x-coordinate of the item relative to the scene
@param y y-coordinate of the item relative to the scene
@param vx velocity in x-direction
@param vy velocity in y-direction
@param pic pointer to the item's main image
@param pic2 pointer to the item's second image
@param p pointer to the player of the game
@param main pointer to the mainwindow of the game

Note about velocities: Because items move across the screen from right to left, but because the scene coordinates move in a positive direction from left to right, all vx velocites are negative numbers. vy velocities are positive to travel down the screen and negative to travel upwards.
*/
Item::Item(int x, int y, int vx, int vy, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main)
{
	x_ = x;
	y_ = y;
	setPos(x_,y_);
	vx_ = vx;
	vy_ = vy;
	pic_ = pic;
	pic2_ = pic2;
	setPixmap(*pic_);
	p_ = p;
	main_ = main;
}

Item::~Item()
{
}
