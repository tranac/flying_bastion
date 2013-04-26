#include "gargoyle.h"
#include "main.h"

Gargoyle::Gargoyle(int y, Player* p, QPixmap* pic, QPixmap* pic2, MainWindow* main) : Item(645,y,-1,0,pic,pic2,p,main)
{
}

Gargoyle::~Gargoyle()
{
}

void Gargoyle::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
		
	//if inline with player & not a third of the way across screen, match player y-coordinate
	if((y_ > 200))
	{
		y_ = p_->getY();
	}
	else
		y_ = y_ + vy_;

	//change xy coordinates
	x_ = x_ + vx_;
	setPos(x_,y_);
}

void Gargoyle::collide()
{
	if(Item::collide())
		main_->loseLife();
}
