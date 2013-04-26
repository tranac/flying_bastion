#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include "player.h"

class Item : public QGraphicsPixmapItem
{
  public:
  	Item(int x, int y, int vx, int vy, QPixmap* pic);
	~Item();
  	virtual void move() = 0;
  protected:
	int x_;
	int y_;
	int vx_;
	int vy_;
	QPixmap* pic_;
} ;

#endif
