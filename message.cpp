#include "message.h"

Message::Message()
{
	setPos(140,50);
	start_ = new QPixmap("images/welcome.png","png");
	end_ = new QPixmap("images/gameover.png","png");
}

Message::~Message()
{
	delete start_;
	delete end_;
}

void Message::setEnd()
{
	setPixmap(*end_);
}

void Message::setStart()
{
	setPixmap(*start_);
}
