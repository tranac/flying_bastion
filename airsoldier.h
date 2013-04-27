#ifndef AIRSOLDIER_H
#define AIRSOLDIER_H

#include "item.h"

/** Derived from Item class. One of the enemies. */
class AirSoldier : public Item
{
  public:
	AirSoldier(QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~AirSoldier();
	void move();
	void collide();
} ;

#endif
