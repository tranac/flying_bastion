#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>

/** Used for a scrolling background. */
class Background : public QGraphicsPixmapItem
{
  public:
  Background(int x, QPixmap* l1, QPixmap* l2, QPixmap* l3);
  	~Background();
  	void move();
	void setImage(int l);
  private:
  	int x_;
  	int y_;
  	QPixmap* l1_;
	QPixmap* l2_;
	QPixmap* l3_;
} ;

#endif
