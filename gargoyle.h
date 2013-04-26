#ifndef GARGOYLE_H
#define GARGOYLE_H

#include "item.h"

class Gargoyle : public Item
{
  public:
	Gargoyle(Player* p, QPixmap* pic, QPixmap* pic2, class MainWindow* main);
	~Gargoyle();
	void move();
	void collide();
} ;

#endif
