/**
This class acts as the primary main window for the game GUI. It holds the overall scene, the board, the options, all of the necessary functions.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow();
	~MainWindow();
private:
} ;

#endif
