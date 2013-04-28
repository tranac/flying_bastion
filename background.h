#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>

/** Used for a scrolling background. */
class Background : public QGraphicsPixmapItem
{
  public:
  	Background(int x, QPixmap* pic);
  	~Background();
  	void move();
  private:
  	int x_;
  	int y_;
  	QPixmap* pic_;
} ;

#endif
