#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

/** Models a player in the game. */
class Player : public QGraphicsPixmapItem
{
  public:
  	Player(class MainWindow* main);
  	~Player();
  	void move(int x);
  	/** @return x-coordinate of the player */
  	int getX() { return x_; }
  	/** @return y-coordinate of the player */
  	int getY() { return y_; }
  	void collide();
  private:
  	int x_;
  	int y_;
  	QPixmap* pic_;
  	QPixmap* pic2_;
  	class MainWindow* main_;
} ;

#endif
