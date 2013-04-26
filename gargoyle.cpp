#include "gargoyle.h"
#include "main.h"

Gargoyle::Gargoyle(int y, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(645,y,-1,0,pic,pic2,p,main)
{
}

Gargoyle::~Gargoyle()
{
}

void Gargoyle::move()
{
	//if inline with player & not a third of the way across screen, match player y-coordinate
	if((x_ > 400))
	{
		y_ = p_->getY();
	}
	else
	{
		y_ = y_ + vy_;
		setPixmap(*pic2_);
	}
	//change xy coordinates
	x_ = x_ + vx_;
	setPos(x_,y_);
}

void Gargoyle::collide()
{
	if((x_ == p_->getX()+83) && (y_ >= p_->getY()) && (y_ <= p_->getY() +  82))
		main_->loseLife();
}
