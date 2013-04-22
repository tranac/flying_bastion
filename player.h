#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

class Player : public Item
{
  public:
  	Player(QPixmap* pic) : Item(50,200,0,5,pic) { }
  	void move();
} ;

#endif
