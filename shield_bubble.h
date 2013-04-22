#ifndef SHIELD_BUBBLE_H
#define SHIELD_BUBBLE_H

#include "item.h"

class ShieldBubble : public Item
{
  public:
  	ShieldBubble(int y, int vx, QPixmap* pic) : Item(600,y,vx,0,pic) { }
  	void move();
} ;

#endif
