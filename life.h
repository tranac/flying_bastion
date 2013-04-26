#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>

class Life : public QGraphicsPixmapItem
{
  public:
	Life(int x, int y, QPixmap* pic);
	~Life();
	
	int getX() { return x_; }
	int getY() { return y_; }
  private:
	int x_;
	int y_;
  	QPixmap* pic_;
} ;

#endif
