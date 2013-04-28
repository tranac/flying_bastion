#include "help.h"

/**
Creates a Player object. Initial coordinates are always (140,50). No initial Pixmap is set.
*/
Help::Help()
{
	setPos(-15,15);
	help_ = new QPixmap("images/help.png","png");
	setPixmap(*help_);
}

/**
Deletes dynamically-allocated Pixmap images.
*/
Help::~Help()
{
	delete help_;
}
