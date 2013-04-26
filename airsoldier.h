#ifndef AIRSOLDIER_H
#define AIRSOLDIER_H

#include "item.h"

class AirSoldier : public Item
{
  public:
	AirSoldier(QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~AirSoldier();
	void move();
	void collide();
} ;

#endif
