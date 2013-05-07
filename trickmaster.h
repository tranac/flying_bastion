#ifndef TRICKMASTER_H
#define TRICKMASTER_H

#include "item.h"

/** Derived from Item class. One of the enemies. */
class Trickmaster : public Item
{
  public:
  	Trickmaster(QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~Trickmaster();
	void move();
	void collide();
 private:
 	int moves;
} ;

#endif
