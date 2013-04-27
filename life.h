#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>

/** Used as an indicator of a life. */
class Life : public QGraphicsPixmapItem
{
  public:
	Life(int x, int y, QPixmap* pic);
	~Life();
	/** @return the x-coordinate of the Life image */
	int getX() { return x_; }
	/** @return the y-coordinate of the Life image */
	int getY() { return y_; }
  private:
	int x_;
	int y_;
  	QPixmap* pic_;
} ;

#endif
