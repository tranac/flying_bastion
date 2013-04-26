#ifndef MESSAGE_H
#define MESSAGE_H

#include <QGraphicsPixmapItem>

class Message: public QGraphicsPixmapItem
{
  public:
	Message();
	~Message();
	
	void setEnd();
	void setStart();
  private:
  	QPixmap* start_;
  	QPixmap* end_;
} ;

#endif
