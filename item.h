#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <cstdlib>
#include "player.h"

class Item : public QGraphicsPixmapItem
{
  public:
  	Item(int x, int y, int vx, int vy, QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~Item();
  	virtual void move() = 0;
  	int getX() { return x_; }
  	int getY() { return y_; }
  	bool collide();
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
