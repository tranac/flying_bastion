#include "mainwindow.h"
#include <iostream>

/**
Constructor. Creates the overall scenes and layouts, the options toolbar, the timer, et cetera. A board is not created until a game is started.

*/
MainWindow::MainWindow()
{

}

/**
Deconstructor. Deletes the dynamically-allocated objects. Because QT deletes the children of a parent if the parent is deleted, only the main layout is deleted as (almost) everything is its child or grandchild. The dynamically allocated Board is deleted and the timer is delete.
*/
MainWindow::~MainWindow()
{

}
