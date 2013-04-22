#ifndef ARROW_H
#define ARROW_H

#include "item.h"

class Arrow : public Item
{
  public:
  	Arrow(int y, int vx, QPixmap* pic) : Item(600,y,vx,0,pic) { }
  	void move();
} ;

#endif
