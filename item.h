#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>

class Item : public QGraphicsPixmapItem
{
  public:
  	Item(int x, int y, int vx, int vy, QPixmap* pic);
	~Item();
  	virtual void move() = 0;
  	int getX() { return x_; }
  	int getY() { return y_; }
  protected:
	int x_;
	int y_;
	int vx_;
	int vy_;
	QPixmap* pic_;
} ;

#endif
