#include "message.h"

/**
Creates a Player object. Initial coordinates are always (140,50). No initial Pixmap is set.
*/
Message::Message()
{
	setPos(140,50);
	start_ = new QPixmap("images/welcome.png","png");
	end_ = new QPixmap("images/gameover.png","png");
}

/**
Deletes dynamically-allocated Pixmap images.
*/
Message::~Message()
{
	delete start_;
	delete end_;
}

/**
Sets Pixmap to the end_ image.
*/
void Message::setEnd()
{
	setPixmap(*end_);
}

/**
Sets Pixmap to the start_ image.
*/
void Message::setStart()
{
	setPixmap(*start_);
}
