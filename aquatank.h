#ifndef AQUATANK_H
#define AQUATANK_H

#include "item.h"

class Aquatank : public Item
{
  public:
	Aquatank(int y, int vx);
	~Aquatank();
	void move();
} ;

#endif
