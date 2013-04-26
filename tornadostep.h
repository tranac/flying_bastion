#ifndef TORNADOSTEP_H
#define TORNADOSTEP_H

#include "item.h"

class TornadoStep : public Item
{
  public:
	TornadoStep(int y, QPixmap* pic, QPixmap* pic2);
	~TornadoStep();
	void move();
  private:
  	QPixmap* pic2_;
  	int c_;
} ;

#endif
