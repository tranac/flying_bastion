#include "main.h"
#include <iostream>

MainWindow::MainWindow()
{
  //set variables
	started = false;
	score_ = 0;
	lives_ = 0;
	executions = 0;
	speed = 100;
	
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
/*s
  //create menu bar
  	menu = menuBar();
  	action = menu->addAction("Start");
*/
/*******************************************************************
	pic = new QPixmap("images/aquatank.png","png");
	item = new QGraphicsPixmapItem;
	item->setPos(20,20);
	item->setPixmap(*pic);
	scene->addItem(item);
********************************************************************/
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
  	name = new QLineEdit("User");
  	name->setReadOnly(true);
//  	name->setWindowOpacity(0);
  	name->setFixedWidth(100);
  	options->addWidget(name);
  //create score show
  	score = new QLineEdit(QString::number(0));
  	score->setReadOnly(true);
//  	score->setWindowOpacity(0);
  	score->setFixedWidth(100);
  	options->addWidget(score);
  	/***********************ADD IN TEXT TO ENTER USERNAME*********/
  //create input for name
	name_ = new QLineEdit();
 	scene->addWidget(name_);
 	
  //create timer
  	timer = new QTimer();
	timer->setInterval(speed);
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
		name->setText(n);
		//make name invisible and unaccessible
		name_->setEnabled(false);
		name_->setHidden(true);
		name_->setReadOnly(true);
		
		started = true;
		lives_ = 3;
		
		queue = new QQueue<Item*>;
		//create flags
	}
	else
	{
		//reset values
		timer->stop();
		speed = 100;
		timer->setInterval(speed);
		finished = false;
		score_ = 0;
		lives_ = 3;
		executions = 0;

		//delete current player and objects
		
	}
		player = new Player();
		scene->addItem(player);
		
		Item* temp = new Aquatank(-20,-1);
		//start timer
		timer->start();
}

void MainWindow::pauseGame()
{
	if(timer->isActive())
	{
		timer->stop();
		pause->setText("Continue");
	}
	else
	{
		timer->start();
		pause->setText("Pause");
	}
}

void MainWindow::handleTimer()
{
	//check collisions
/*
	
*/	
	//check if dead
	if(!lives_)
	{
		endGame();
		return;
	}

	items = new QQueue<int>;
	items->enqueue(executions);
	
	//move items
	/*
	QQueue<int>::iterator it = items->begin();
	while(it != items->end())
	{
		int x = items->dequeue();
		std::cout << x << std::endl;
		++it;
	}
	*/

	int v;
	//check if mouse is being pressed for player velocity
	if(qApp->mouseButtons() == Qt::LeftButton)	
		v = 0;
//		std::cout << "Huzzah!" << std::endl;
	else
		v = 1;
//		std::cout << "Falling." << std::endl;

	//create enemies
	if((executions % 10))
	{
		createEnemies();
	}
	
	player->move(v);
	aqua->move();

	//increase score
	score_++;
	score->setText(QString::number(score_));
	executions++;
	
	//check if need speeding up
	switch(executions)
	{
		case 100:
		case 350:
		case 1000:
		case 5000:
		{
			speed = speed / 2;
			timer->setInterval(speed);
		}
	}
}

void MainWindow::createEnemies()
{
	//randomly create enemies
	srand(time(0));
	int a = rand() % 10;
	switch(a)		//random cases
	{
		//create red nocture / arrow
		case 1:
		{
			std::cout << "Red Nocturne!" << std::endl;
			return;
		}
		//create aquatank / dragon
		case 2:
		{
			std::cout << "Aquatank!" << std::endl;
			return;
		}
		//chance to create tornado step / gem
		case 3:
		{
			int b = rand() % 2;
			//create gem
			if(b == 0)
			{
			std::cout << "Tornado Step!" << std::endl;
			}
			return;
		}
		//chance to create mushroom / bubble
		case 4:
		{
			int b = rand() % 2;
			//create bubble
			if(b == 1)
			{
			std::cout << "White Mushroom!" << std::endl;
			}
			return;
		}
		default:
		{
			return;
		}
	}
}

void MainWindow::endGame()
{
	timer->stop();
	std::cout << "Dead!" << std::endl;
	score_ = 0;
	finished = true;
}
