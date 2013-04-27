#ifndef REDNOCTURNE_H
#define REDNOCTURNE_H

#include "item.h"

/** Derived from Item class. One of the enemies. */
class RedNocturne : public Item
{
  public:
	RedNocturne(int y, int vx, QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~RedNocturne();
	void move();
	void collide();
} ;

#endif
