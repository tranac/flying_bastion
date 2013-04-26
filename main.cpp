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
	canLose = true;
	
  //create Pixmap images
  	as1 = new QPixmap("images/airsoldier1.png","png");
  	as2 = new QPixmap("images/airsoldier2.png","png");
  	at = new QPixmap("images/aquatank.png","png");
  	rn1 = new QPixmap("images/rednocturne1.png","png");
  	rn2 = new QPixmap("images/rednocturne2.png","png");
  	ts1 = new QPixmap("images/tornadostep1.png","png");
  	ts2 = new QPixmap("images/tornadostep2.png","png");
  	wm1 = new QPixmap("images/whitemushroom1.png","png");
  	wm2 = new QPixmap("images/whitemushroom2.png","png");
  	l = new QPixmap("images/life.png","png");
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
	scene->setSceneRect(0,0,650,350);
	view = new QGraphicsView(scene);
	view->setFixedSize(675,375);
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
	s = new QFormLayout();
  	score = new QLineEdit(QString::number(0));
  	score->setReadOnly(true);
//  	score->setWindowOpacity(0);
  	score->setFixedWidth(100);
  	s->addRow("Score",score);
  	options->addLayout(s);
  	
  	/***********************ADD IN TEXT TO ENTER USERNAME*********/
  //create input for name
	name_ = new QLineEdit();
	name_->setGeometry(250,150,150,30);
//	QRect r(250,150,150,30);
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
		if(n == "")
			return;
		
			name->setText(n);
			//make name invisible and unaccessible
			name_->setEnabled(false);
			name_->setHidden(true);
			name_->setReadOnly(true);
		
			started = true;
			lives_ = 3;
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
		lives.clear();
		executions = 0;

		//delete current player and objects
		
	}
		player = new Player();
		scene->addItem(player);
		
		int x = 5;
		for(int i=0;i<3;i++)
		{
			life = new Life(x,5,l);
			scene->addItem(life);
			lives.push_back(life);
			x = x+15;
		}
		
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
	//check collisions against wall
	if(canLose)
	{
		if((player->getY() == 0) || ((player->getY() + 50) == 350))
		{
			loseLife();
			return;
		}
	}
	else if(lose == 51)
	{
		canLose = true;
		lose = 0;
	}
	else
	{
		player->flash();
		lose++;
	}
	
	//check collisions against enemies
	

	//check if dead
	if(!lives_)
	{
		endGame();
		return;
	}
	
	//move items
	for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		Item* temp = *it;
		temp->move();
	}

	//move player
	int v;
	//check if mouse is being pressed for player velocity
	if(qApp->mouseButtons() == Qt::LeftButton)	
		v = 0;
	else
		v = 1;
	player->move(v);

	//create enemies
	if(!(executions % 10))
	{
		createEnemies();
	}

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
			speed = speed / 3;
			timer->setInterval(speed);
		}
	}
}

void MainWindow::createEnemies()
{

/******************THING*******************************************/
		newItem = new RedNocturne(125,-3,rn1,rn2);
		scene->addItem(newItem);
		items.push_back(newItem);

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

void MainWindow::loseLife()
{
	lives_--;
	Life* life = lives.at(lives_);
	scene->removeItem(life);
	lives.pop_back();
	player->flash();
	lose = 0;
	canLose = false;
}

void MainWindow::endGame()
{
	timer->stop();
	std::cout << "Dead!" << std::endl;
	score_ = 0;
	finished = true;
	canLose = false;
	lose = 0;
}
