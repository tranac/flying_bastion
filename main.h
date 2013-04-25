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
#include <QListWidget> 	//used for A* solution
#include <QPushButton>	//used for Start, Quit, and A* buttons
#include <QTextEdit>	//used for error messages
#include <QLineEdit>	//used for initial inputs
#include <QTimer>		//used for move function
#include <QString>
#include <QColor>

#include <cmath>
#include <stdexcept>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow();	//takes in number of commandline arguments
    ~MainWindow();
    
//  	void mousePressEvent(QMouseEvent* event);
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

	QLineEdit*    name_;
	QTextEdit*	  name;
	QTextEdit*	  score;

	QPushButton*  start;	//start game
	QPushButton*  pause;	//pause game
	QPushButton*  quit;		//quit game
	
	QTimer*	timer;
	
	int score_;
	int lives_;
	int pv_;				//player velocity
} ;

#endif

