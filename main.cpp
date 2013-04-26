#include "main.h"
#include <iostream>

MainWindow::MainWindow()
{
  //set variables
	started = false;
	finished = true;
	score_ = 0;
	lives_ = 0;
	executions = 0;
	speed = 100;
	canLose = true;
	
  //create Pixmap images
  	as1 = new QPixmap("images/airsoldier1.png","png");
  	as2 = new QPixmap("images/airsoldier2.png","png");
  	at = new QPixmap("images/aquatank.png","png");
  	g1 = new QPixmap("images/gargoyle1.png","png");
  	g2 = new QPixmap("images/gargoyle2.png","png");
  	rn1 = new QPixmap("images/rednocturne1.png","png");
  	rn2 = new QPixmap("images/rednocturne2.png","png");
  	ts1 = new QPixmap("images/tornadostep1.png","png");
  	ts2 = new QPixmap("images/tornadostep2.png","png");
  	wm1 = new QPixmap("images/whitemushroom1.png","png");
  	wm2 = new QPixmap("images/whitemushroom2.png","png");
  	l = new QPixmap("images/life.png","png");
  	bg = new QPixmap("images/background.png","png");
  	bgs = new QPixmap("images/startbackground.png","png");
  //create overall layout
	this->setGeometry(1,0,20,20);
	
	window = new QWidget;
	setCentralWidget(window);
	layout = new QVBoxLayout(window);
	window->setLayout(layout);
	
  //create options sidebar 
	options = new QHBoxLayout();
	layout->addLayout(options);
  //create gamespace
	scene = new QGraphicsScene();
	scene->setSceneRect(0,0,650,350);
	view = new QGraphicsView(scene);
	view->setFixedSize(675,375);
	QRect r(0,0,675,375);
	QColor c(Qt::black);
	QBrush b(c,*bgs);
	view->setBackgroundBrush(b);
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
  	
  //create message text
  	message = new Message();
  	message->setStart();
  	scene->addItem(message);
  
  //create input for name
	name_ = new QLineEdit();
	name_->setGeometry(300,250,190,30);
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
		//if empty, the game won't start;
		if(n == "")
			return;
		
		//create username and score output
		n = n + " Score";
		s = new QFormLayout();
 	 	score = new QLineEdit(QString::number(score_));
 	 	score->setReadOnly(true);
  		score->setFixedWidth(100);
  		s->addRow(n,score);
  		options->addLayout(s);
  		options->setStretch(3,0.5);
  		
		//make welcome screen invisible and unaccessible
		name_->setEnabled(false);
		name_->setHidden(true);
		name_->setReadOnly(true);
	
		started = true;
		lives_ = 3;
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
		lose = 0;
		canLose = true;
		
		//delete player
		delete player;
/***************DELETE CURRENT OBJECTS********************/
/***************DELETE LIVES******************************/
	}
	
		//hide message
		message->setVisible(false);
		
		//create new player
		player = new Player();
		scene->addItem(player);
		
		//create lives
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
	if(!finished)
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
	if(!(executions % 50))
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


	//randomly create enemies
	srand(time(0));
	int a = rand() % 6;
	int b = rand() % 330;
	switch(a)		//random cases
	{
		//create red nocture / arrow
		case 1:
		{
			newItem = new RedNocturne(b,-3,rn1,rn2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
		//create aquatank / dragon
		case 2:
		{
			newItem = new Aquatank(b,-3,at,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
		//chance to create white mushroom
		case 3:
		{
			int c = rand() % 7;
			//create gem
			if(!c)
			{
				newItem = new WhiteMushroom(b,player,wm1,wm2,this);
				scene->addItem(newItem);
				items.push_back(newItem);
			}
			return;
		}
		//chance to create tornado step
		case 4:
		{
			int c = rand() % 7;
			//create gem
			if(!c)
			{
				newItem = new TornadoStep(b,ts1,ts2,player,this);
				scene->addItem(newItem);
				items.push_back(newItem);
			}
			return;
		}
		case 5:
		{
			newItem = new AirSoldier(as1,as2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
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
	scene->removeItem(player);
	
	for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		Item* temp = *it;
		scene->removeItem(temp);
		/*************DELETE ITEMS******************/
	}
	
	//delete vector
	items.clear();
	
	message->setEnd();
	message->setVisible(true);

}

void MainWindow::gainLife()
{

}

void MainWindow::gainPoints()
{
	score_ = score_ + 50;
	score->setText(QString::number(score_));
}
