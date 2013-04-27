#ifndef GARGOYLE_H
#define GARGOYLE_H

#include "item.h"

/** Derived from Item class. One of the enemies. */
class Gargoyle : public Item
{
  public:
  Gargoyle(int y,  QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~Gargoyle();
	void move();
	void collide();
} ;

#endif
