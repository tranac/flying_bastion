#ifndef DRAGON_H
#define DRAGON_H

#include "item.h"

class Dragon : public Item
{
  public:
  	Dragon(int y, int vx, int vy, QPixmap* pic) : Item(600,y,vx,vy,pic) { }
  	void move();
} ;

#endif
