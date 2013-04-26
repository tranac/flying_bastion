#ifndef TORNADOSTEP_H
#define TORNADOSTEP_H

#include "item.h"

class TornadoStep : public Item
{
  public:
	TornadoStep(int y, QPixmap* pic, QPixmap* pic2, Player* p, class MainWindow* main);
	~TornadoStep();
	void move();
	void collide();
  private:
  	int c_;
} ;

#endif
