#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QTimer>
#include <QString>
#include <QColor>
#include <QVector>		//used for moving items
#include <QPixmap>

#include "life.h"
#include "player.h"
#include "item.h"
#include "aquatank.h"
#include "rednocturne.h"
#include "airsoldier.h"
#include "whitemushroom.h"
#include "tornadostep.h"

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
	void loseLife();
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
	
	QFormLayout*  n;
	QLineEdit*    name_;
	QLineEdit*	  name;
	QLineEdit*	  score;

	QPushButton*  start;	//start game
	QPushButton*  pause;	//pause game
	QPushButton*  quit;		//quit game
	
	Player* player;
	
	QTimer*	timer;
	
	QVector<Item*> items;		//list of items in screen
	Item*		   newItem;
	
	QVector<Life*> lives;
	Life*		   life;
	bool canLose;
	int lose;
	
	int score_;
	int lives_;
	int pv_;				//player velocity
	int executions;
	int speed;				//interval for timer
	
	QPixmap* as1;
	QPixmap* as2;
	QPixmap* at;
	QPixmap* rn1;
	QPixmap* rn2;
	QPixmap* ts1;
	QPixmap* ts2;
	QPixmap* wm1;
	QPixmap* wm2;
	QPixmap* l;
} ;

#endif

