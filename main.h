#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <string>

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QTimer>
#include <QString>
#include <QColor>
#include <QPalette>
#include <QVector>
#include <QPixmap>
#include <QLabel>

#include "airsoldier.h"
#include "aquatank.h"
#include "audio.h"
#include "background.h"
#include "gargoyle.h"
#include "help.h"
#include "item.h"
#include "life.h"
#include "message.h"
#include "player.h"
#include "score.h"
#include "rednocturne.h"
#include "tornadostep.h"
#include "trickmaster.h"
#include "whitemushroom.h"
#include "wyvern.h"

/**
Main class of the game. Holds the game window, members, and functions.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    
	void createEnemies();	
	void endGame();
	void loseLife();
	void gainLife();
	void gainPoints();
	void deleteEnemies();
	void setLife(int x);
protected slots:
	void startGame();		//starts & restarts games
	void pauseGame();		//pauses & continues game
	void toggleSound();		//mutes & unmutes background music
	void toggleHelp();		//shows & hides help screen
	void handleTimer();		//handles timer
private:
	Audio* audio;			//background music
	
	QWidget*		window;	//central widget
	QVBoxLayout* 	layout;	//central layout
	QHBoxLayout* 	options;//toolbar
	QHBoxLayout*	gameplay;
	QGraphicsScene* scene;	//game window
	QGraphicsView* 	view;	//game view
	QTimer*	timer;			//timer
	
	QLineEdit*    name_;	//input for user name
	QLineEdit*	  score;	//score display
	QFormLayout*  s;		//user name & score display
	Score* scores;

	QPushButton*  start;	//start game
	QPushButton*  pause;	//pause game
	QPushButton*  quit;		//quit game
	QPushButton*  help;		//help button
	QRadioButton* invincible;//invincibility mode
	QPushButton*  mute;		//mute music
	QLabel* i;
	QLabel* lvl;
	
	Message* message;		//start and gameover screen images
	Help* helpscreen;		//help screen image

	Player* player;			//player
		
	QVector<Item*> items;	//list of items in screen
	Item*		   newItem;	//temp to add in new items
	
	Life*		   life;	//pixmap item displayed for each life
	QVector<Life*> lives;	//vector for lives
	int  c;					//num of counts for buffer
	bool canCollide;		//flag for collision buffer
	
	bool started;			//flag for started games
	bool finished;			//flag for finished games
	
	int score_;				//score
	int lives_;				//lives
	int level;
	int executions;			//num of timeouts(); used for speed up
	int len;				//interval for timer to speed up
	int speed;				//timer interval
	
	QLabel* points;			//shown to notify user of bonus points
	
	Background* background;	//scrolling background image 1
	Background* background2;//scrolling background image 2
	
	QPixmap* as1;		//pixmap items for player, items, and screens
	QPixmap* as2;
	QPixmap* as3;
	QPixmap* at;
	QPixmap* g1;
	QPixmap* g2;
	QPixmap* rn1;
	QPixmap* rn2;
	QPixmap* tm1;
	QPixmap* tm2;
	QPixmap* ts1;
	QPixmap* ts2;
	QPixmap* w1;
	QPixmap* w2;
	QPixmap* wm1;
	QPixmap* wm2;
	QPixmap* l;
	QPixmap* l1;
	QPixmap* l2;
	QPixmap* l3;
	QPixmap* bgs;
} ;

#endif

