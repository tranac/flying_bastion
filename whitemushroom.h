#ifndef WHITEMUSHROOM_H
#define WHITEMUSHROOM_H

#include "item.h"

class WhiteMushroom : public Item
{
  public:
	WhiteMushroom(int y, Player* p, QPixmap* pic, QPixmap* pic2, class MainWindow* main);
	~WhiteMushroom();
	void move();
	void collide();
} ;

#endif
