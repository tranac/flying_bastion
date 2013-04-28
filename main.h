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
#include <QRadioButton>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QTimer>
#include <QString>
#include <QColor>
#include <QVector>
#include <QPixmap>
#include <QLabel>


#include "audio.h"
#include "message.h"
#include "life.h"
#include "player.h"
#include "item.h"
#include "aquatank.h"
#include "rednocturne.h"
#include "airsoldier.h"
#include "whitemushroom.h"
#include "tornadostep.h"
#include "gargoyle.h"
#include "background.h"

#include <cmath>
#include <stdexcept>
#include <cstdlib>

/**
Main class of the game. Holds the game window, members, and functions.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow();	//takes in number of commandline arguments
    ~MainWindow();
    
	void createEnemies();
	void loseLife();
	void endGame();
	void gainLife();
	void gainPoints();
	void deleteEnemies();
	void setLife(int x);
protected slots:
	void startGame();
	void pauseGame();
	void handleTimer();
private:
	Audio* audio;
	
	bool started;
	bool finished;
	
	QWidget*		window;
	QVBoxLayout* 	layout;
	QHBoxLayout* 	options;
	
	QGraphicsScene* scene;	//game window
	QGraphicsView* 	view;
	
	QLineEdit*    name_;
	QLineEdit*	  score;
	QFormLayout*  s;

	QPushButton*  start;	//start game
	QPushButton*  pause;	//pause game
	QPushButton*  quit;		//quit game
	QRadioButton* invincible;//invincibility mode
	
	Message* message;
	Player* player;
	
	QTimer*	timer;
	
	QVector<Item*> items;	//list of items in screen
	Item*		   newItem;	
	
	Life*		   life;	//pixmap item displayed for each life
	QVector<Life*> lives;	//vector for lives
	bool canLose;			//buffer after losing a life
	int lose;				//num of counts for buffer
	
	int score_;				//score
	int lives_;				//lives
	int executions;			//num of timeouts()
	int len;				//interval for timer to speed up
	int speed;				//timer interval
	
	Background* background;
	Background* background2;
	
	QPixmap* as1;			//enemy pics
	QPixmap* as2;
	QPixmap* at;
	QPixmap* g1;
	QPixmap* g2;
	QPixmap* rn1;
	QPixmap* rn2;
	QPixmap* ts1;
	QPixmap* ts2;
	QPixmap* wm1;
	QPixmap* wm2;
	QPixmap* l;
	QPixmap* bg;			//background
	QPixmap* bgs;			//start background
} ;

#endif

