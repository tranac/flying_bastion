#ifndef REDNOCTURNE_H
#define REDNOCTURNE_H

#include "item.h"

class RedNocturne : public Item
{
  public:
	RedNocturne(int y, int vx, QPixmap* pic, QPixmap* pic2);
	~RedNocturne();
	void move();
  private:
  	QPixmap* pic2_;
} ;

#endif
