#include "gem.h"

Gem::move()
{
	x_ = x_ + vx_;
	y_ = y_ + vy_;
	setPos(x_,y_);
}
