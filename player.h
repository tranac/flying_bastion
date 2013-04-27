#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

/** Models a player in the game. */
class Player : public QGraphicsPixmapItem
{
  public:
  	Player();
  	~Player();
  	void move(int x);
  	/** @return x-coordinate of the player */
  	int getX() { return x_; }
  	/** @retrurn y-coordinate of the player */
  	int getY() { return y_; }
  private:
  	int x_;
  	int y_;
  	QPixmap* pic_;
  	QPixmap* pic2_;
} ;

#endif
