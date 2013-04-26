#ifndef AIRSOLDIER_H
#define AIRSOLDIER_H

#include "item.h"

class AirSoldier : public Item
{
  public:
	AirSoldier(QPixmap* pic, QPixmap* pic2);
	~AirSoldier();
	void move();
  private:
  	QPixmap* pic2_;
  	int moves_;
} ;

#endif
