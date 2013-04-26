#include "rednocturne.h"
#include "main.h"

//check position
RedNocturne::RedNocturne(int y, int vx, QPixmap* pic, QPixmap* pic2, Player* p, MainWindow* main) : Item(645,y,vx,0,pic,pic2,p,main)
{
}

RedNocturne::~RedNocturne()
{
}

void RedNocturne::move()
{
	//every other move, change image
	if(x_ % 2)
		setPixmap(*pic2_);
	else
		setPixmap(*pic_);
	//change xy coordinates
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}

void RedNocturne::collide()
{
	if(Item::collide())
		main_->loseLife();
}
