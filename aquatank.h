#ifndef AQUATANK_H
#define AQUATANK_H

#include "item.h"

/** Derived from Item class. One of the enemies. */
class Aquatank : public Item
{
  public:
	Aquatank(int y, QPixmap* pic, Player* p, class MainWindow* main);
	~Aquatank();
	void move();
	void collide();
} ;

#endif
