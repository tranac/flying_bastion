#ifndef WHITEMUSHROOM_H
#define WHITEMUSHROOM_H

#include "item.h"
#include "player.h"

class WhiteMushroom : public Item
{
  public:
	WhiteMushroom(int y, Player* p, QPixmap* pic, QPixmap* pic2);
	~WhiteMushroom();
	void move();
  private:
  	QPixmap* pic2_;
  	int moves_;
  	Player* p_;
} ;

#endif
