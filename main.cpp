#include "main.h"
#include <iostream>

MainWindow::MainWindow()
{
	started = false;
	score_ = 0;
	lives_ = 0;
  //create overall layout
	this->setGeometry(1,0,20,20);
	
	window = new QWidget;
	setCentralWidget(window);
	layout = new QVBoxLayout(window);
	window->setLayout(layout);
	
  //create options sidebar 
	options = new QHBoxLayout();
	layout->addLayout(options);
  //create view space
	scene = new QGraphicsScene();	
	view = new QGraphicsView(scene);
	view->setFixedSize(650,350);
	QColor c(16,64,46,255);
	QBrush b(c);
	scene->setBackgroundBrush(b);
 	layout->addWidget(view);

  //create start button
  	start = new QPushButton("Start Game");
	options->addWidget(start);
	QObject::connect(start,SIGNAL(clicked()),this,SLOT(startGame()));

  //create pause button
  	pause = new QPushButton("Pause Game");
  	options->addWidget(pause);
  	QObject::connect(pause,SIGNAL(clicked()),this,SLOT(pauseGame()));
  //create quit button
	quit = new QPushButton("Quit Game");
	options->addWidget(quit);
	QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
  	
  //create name show
  	name = new QTextEdit("User");
  	name->setReadOnly(true);
  	name->setWindowOpacity(0);
  	name->setFixedSize(100,30);
  	options->addWidget(name);
  //create score show
  	score = new QTextEdit(QString::number(0));
  	score->setReadOnly(true);
  	score->setWindowOpacity(0);
  	score->setFixedSize(100,30);
  	options->addWidget(score);
  		
  //create input for name
	name_ = new QLineEdit("Please Enter a Username");
 	scene->addWidget(name_);
 	
  //create timer
  	timer = new QTimer();
	timer->setInterval(50);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(handleTimer()));
}

MainWindow::~MainWindow()
{
	delete timer;
}

void MainWindow::startGame()
{
	if(!started)
	{
		//grab username
		QString n = name_->text();
		name->setPlainText(n);
		//make name invisible and unaccessible
		name_->setEnabled(false);
		name_->setHidden(true);
		name_->setReadOnly(true);
		
		started = true;
		lives_ = 3;
	}
	
	//if game is finished, start over
	if(finished)
	{
		score_ = 0;
		lives_ = 3;
		finished = false;	
	}
	
	timer->start();
}

void MainWindow::pauseGame()
{
	timer->stop();
}

void MainWindow::handleTimer()
{
	//check collisions
	
	

	//check if dead
	if(!lives_)
	{
		timer->stop();
		std::cout << "Dead!" << std::endl;
		score_ = 0;
		finished = true;
		return;
	}

	//if not dead, move items
	
		//check if mouse is being pressed for player velocity
		if(qApp->mouseButtons() == Qt::LeftButton)
			std::cout << "Huzzah!" << std::endl;
		else
			std::cout << "Falling." << std::endl;


	//increase score
	score_++;
	score->setPlainText(QString::number(score_));
	
	//check if need speeding up
}
/*
void MainWindow::mousePressEvent(QMouseEvent* event)
{
	QWidget::mousePressEvent(event);
	if(started)
	{
		std::cout << "Success!" << std::endl;
	}
}*/
