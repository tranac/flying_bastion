#ifndef REDNOCTURNE_H
#define REDNOCTURNE_H

#include "item.h"

class RedNocturne : public Item
{
  public:
	RedNocturne(int y, int vx);
	~RedNocturne();
	void move();
  private:
  	QPixmap* pic2_;
} ;

#endif
