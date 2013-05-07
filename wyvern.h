#ifndef WYVERN_H
#define WYVERN_H

#include "item.h"

/** Derived from Item class. One of the enemies. */
class Wyvern : public Item
{
  public:
  	Wyvern(QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~Wyvern();
	void move();
	void collide();
 private:
} ;

#endif
