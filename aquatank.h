#ifndef AQUATANK_H
#define AQUATANK_H

#include "item.h"

class Aquatank : public Item
{
  public:
	Aquatank(int y, int vx, QPixmap* pic, Player* p, class MainWindow* main);
	~Aquatank();
	void move();
	void collide();
} ;

#endif
