#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem
{
  public:
  	Player();
  	~Player();
  	void move(int x);
  	void collidesWith();
  private:
  	int x_;
  	int y_;
  	QPixmap* pic_;
} ;

#endif
