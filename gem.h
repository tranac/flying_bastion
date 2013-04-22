#ifndef GEM_H
#define GEM_H

#include "item.h"

class Gem : public Item
{
  public:
  	Gem(int y, int vx, QPixmap* pic) : Item(600,y,vx,0,pic) { }
  	void move();
} ;

#endif
