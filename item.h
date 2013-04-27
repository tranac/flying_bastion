#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <cstdlib>
#include "player.h"

/** Abstract base item class */
class Item : public QGraphicsPixmapItem
{
  public:
  	Item(int x, int y, int vx, int vy, QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~Item();
	/** Virtual move function */
  	virtual void move() = 0;
  	/** @return x-coordinate of item */
  	int getX() { return x_; }
  	/** @return y-coordinate of item */
  	int getY() { return y_; }
  	/** Virtual collide function */
  	virtual void collide() = 0;
  protected:
	int x_;
	int y_;
	int vx_;
	int vy_;
	QPixmap* pic_;
	QPixmap* pic2_;
	Player* p_;
	class MainWindow* main_;
} ;

#endif
