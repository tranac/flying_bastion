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
  	int getX() { return x_; }
  	int getY() { return y_; }
  private:
  	int x_;
  	int y_;
  	QPixmap* pic_;
} ;

#endif
