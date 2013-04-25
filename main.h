#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>	//used for Start, Quit, and A* buttons
#include <QTextEdit>	//used for error messages
#include <QTextDocument>
#include <QTextObject>
#include <QLineEdit>	//used for initial inputs
#include <QTimer>		//used for move function
#include <QString>
#include <QColor>
#include <QQueue>		//used for moving items

#include <QGraphicsPixmapItem>

#include "things/player.h"

#include <cmath>
#include <stdexcept>
#include <cstdlib>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow();	//takes in number of commandline arguments
    ~MainWindow();
    
	void createEnemies();
	void endGame();
protected slots:
	void startGame();
	void pauseGame();
	void handleTimer();
private:
	bool started;
	bool finished;
	
	QWidget*		window;
	
	QVBoxLayout* 	layout;
	QHBoxLayout* 	options;
	
	QGraphicsScene* scene;	//scene for view
	QGraphicsView* 	view;

//	QTextDocument* welcome;
	QPixmap* pic;
	QGraphicsPixmapItem* item;

	QLineEdit*    name_;
	QLineEdit*	  name;
	QLineEdit*	  score;

//	QMenuBar*	  menu;
//	QAction*	  action;
	QPushButton*  start;	//start game
	QPushButton*  pause;	//pause game
	QPushButton*  quit;		//quit game
	
	Player* player;
	
	QTimer*	timer;
	
	QQueue<int>* items;		//list of items in screen
	int score_;
	int lives_;
	int pv_;				//player velocity
	int executions;
	int speed;				//interval for timer
} ;

#endif

