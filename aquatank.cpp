#include "aquatank.h"
#include "main.h"

Aquatank::Aquatank(int y, int vx, QPixmap* pic, Player* p, MainWindow* main) : Item(645,y,vx,0,pic,NULL,p,main)
{
}

Aquatank::~Aquatank()
{
}

void Aquatank::move()
{
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

void Aquatank::collide()
{
	if((x_ >= p_->getX()+80) && (x_ <= p_->getX()+83) && (y_ >= p_->getY()-5) && (y_ <= p_->getY() + 82))
	{
	//	main_->endGame();
		main_->loseLife();
	}
}
