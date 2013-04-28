#ifndef HELP_H
#define HELP_H

#include <QGraphicsPixmapItem>

/** Used to model help screen */
class Help: public QGraphicsPixmapItem
{
  public:
	Help();
	~Help();
  private:
  	QPixmap* help_;
} ;

#endif
