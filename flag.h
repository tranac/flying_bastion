#ifndef FLAG_H
#define FLAG_H

#include <QGraphicsPixmapItem>

class Flag : public QGraphicsPixmapItem
{
  public:
  	Flag(int x, int y, QPixmap* pic);
  	~Flag();
  private:
  	int x_;
  	int y_;
  	QPixmap* pic_;
} ;

#endif
