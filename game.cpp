/** @mainpage CSCI102 Programming Assignment #5

@section purpose Purpose/Overview

The purpose of these programming assignments is to make a game using QT. The game must including moving objects and will be implemented using timers, GUI input classes, and QT widgets.

@section requirements Requirements

- Must have at least 5 different items in the game, 4 of which must be moving.

- Items must be represented by different classes, and must be stored in a templated data structure, STL container, or QT container.

- New items show up randomly at different times and intervals.

- Users can start, pause, and quit the game.

- Users have a username, a score displayed, and a finite amount of lives.

- Game should speed up as time elapses until its too hard for a human to play.

*/

#include <QtGui/QApplication>
#include <cstdlib>
#include "main.h"

int main(int argc,char* argv[])
{
	QApplication a(argc, argv);
	
	MainWindow w;
	w.show();
	
	return a.exec();
}
