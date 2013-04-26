#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>

class Life : public QGraphicsPixmapItem
{
  public:
	Life(int x, int y, QPixmap* pic);
	~Life();
  private:
	int x_;
	int y_;
  	QPixmap* pic_;
} ;

#endif
