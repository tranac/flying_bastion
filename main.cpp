#include "main.h"
#include <iostream>

/**

*/
MainWindow::MainWindow()
{
  //set variables
	started = false;
	finished = true;
	score_ = 0;
	lives_ = 0;
	executions = 0;
	speed = 15;
	canLose = true;
	len = 3500;
	
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
  //create invincibility option
  	invincible = new QRadioButton("Invincible Mode?",this);
  	options->addWidget(invincible);
  	
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

/**
Deletes the timer. 
*/
MainWindow::~MainWindow()
{
	delete timer;
	delete window;
}

/**
Starts or restarts the game. If a game hasn't been started, it checks for a user name input and, if valid, starts a game.

If a game is in the middle of gameplay, the current items are deleted and values/items are reset to their initialized state.

If a game has ended, initial items are created.

The game timer is started in this function.
*/
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
		speed = 15;
		timer->setInterval(speed);
		score_ = 0;
		lives_ = 3;
		executions = 0;
		lose = 0;
		canLose = true;
		len = 3500;
		
		//delete items if not already deleted
		if(!finished)
			{
			//delete player
			delete player;
			
			//delete enemies
			for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
			{
				Item* temp = *it;
				scene->removeItem(temp);
				delete temp;
			}
			items.clear();
		
			//delete lives
			for(QVector<Life*>::iterator it = lives.begin(); it != lives.end(); ++ it)
			{
				Life* temp = *it;
				scene->removeItem(temp);
				delete temp;
			}
			lives.clear();
			}
		}
		
		finished = false;
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

/**
Pauses the game. Only applicable if the game has already been started. When pressed, the game timer is stopped and the button text changed to "Continue". If pressed again, the text is changed back and the timer started.
*/
void MainWindow::pauseGame()
{
	if(started)
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

/**
Handles the timer every time it timesout. If invincible mode is checked, no collisions will be checked. Otherwise it will first check against the walls and then against the items.

If a player holds no lives, endGame() is called. If not, Items are then moved.

handleTimer() also checks if new enemies should be spawned or if the game should be sped up.
*/
void MainWindow::handleTimer()
{
  if(!invincible->isChecked())
  {
	//check collisions against wall if not invincible
	if(canLose)
	{
		if((player->getY() <= 0) || ((player->getY() + 50) >= 350))
		{
			loseLife();
			return;
		}
	}
	else if(lose == 51)
	{
		canLose = true;
		lose = 0;
		player->setVisible(true);
	}
	else
	{
		if(lose % 2)
			player->setVisible(false);
		else
			player->setVisible(true);
		lose++;
	}
	
	//check collisions against enemies if not invincible
	for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
	  Item* temp = *it;
	  temp->collide();
	}

	//check if dead
	if(!lives_)
	{
		endGame();
		return;
	}
  }
	//check if items left the scene
	deleteEnemies();
	
	//move items
	for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		Item* temp = *it;
		temp->move();
	}

	//move player and checkes mousePress for player velocity
	int v;
	if(qApp->mouseButtons() == Qt::LeftButton)	
		v = 0;
	else
		v = 1;
	player->move(v);

	//create enemies
	if(!(executions % (len/50)))
	{
		createEnemies();
	}

	//increase score and executions
	score_++;
	score->setText(QString::number(score_));
	executions++;
	
	//check if game requires speeding up
	if(!(executions % len) && (len <= 15000))
	{
		speed = speed / 2;
		timer->setInterval(speed);
		len = len + 5000;
	}
}

/**
Creates a new item. The new item is randomized. For WhiteMushrooms and TornadoSteps, they must also be selected by a second random statement.
*/
void MainWindow::createEnemies()
{
	//randomly create enemies
	srand(time(0));
	int a = rand() % 7;
	int b = rand() % 300;
	
	switch(a)
	{
		//create red nocture
		case 1:
		{
			newItem = new RedNocturne(b,-3,rn1,rn2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
		//create aquatank
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
			int c = rand() % 3;
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
			int c = rand() % 3;
			//create gem
			if(!c)
			{
				//make sure b is in boundaries
				if(b > 250)
					b = 200;
				newItem = new TornadoStep(b,ts1,ts2,player,this);
				scene->addItem(newItem);
				items.push_back(newItem);
			}
			return;
		}
		//create air soldier
		case 5:
		{
			newItem = new AirSoldier(as1,as2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
		//create gargoyle
		case 6:
		{
			newItem = new Gargoyle(player->getY(),g1,g2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
	}

}

/**
Called when a player loses a life. Decreases the count and delets a Life image in the corner. Starts the canLose buffer so that a user can avoid the object that just killed them.
*/
void MainWindow::loseLife()
{
	lives_--;
	life = lives.back();
	scene->removeItem(life);
	lives.pop_back();
	player->setVisible(false);
	lose = 0;
	canLose = false;
}

/**
Ends the game. Stops the timer and sets the finished flag. Removes and deletes the player and the items. Also sets the GameOver message.
*/
void MainWindow::endGame()
{
	timer->stop();
	finished = true;
	scene->removeItem(player);

	QVector<Life*>::iterator it = lives.begin();
	while(it != lives.end())
	{
		Life* temp = *it;
		scene->removeItem(temp);
		delete temp;
		++it;
	}
	
	for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		Item* temp = *it;
		scene->removeItem(temp);
		delete temp;
	}
	items.clear();
	
	//set gameover message
	message->setEnd();
	message->setVisible(true);
}

/**
Called by WhiteMushroom. Gives the user an additional life.
*/
void MainWindow::gainLife()
{
	lives_++;
	
	
	Life* end = lives.back();
	life = new Life((end->getX()+15),5,l);
	scene->addItem(life);
	lives.push_back(life);
}

/**
Called by TornadoStep. Gives the user 100 additional points.
*/
void MainWindow::gainPoints()
{
	score_ = score_ + 100;
	score->setText(QString::number(score_));
}

/**
Iterates through the vector of items. If the item has moved past the left boundary, it is deleted.
*/
void MainWindow::deleteEnemies()
{
	QVector<Item*>::iterator it = items.begin();
	
	while(it != items.end())
	{
		Item* temp = *it;
		if(temp->getX() <= -20)
	 	 {
			it = items.erase(it);
			scene->removeItem(temp);
			delete temp;
		}
	  	else
		  ++it;
	}
}

/**
@param x number of lives to set lives_ to
Called by Aquatank. Sets the number of lives to x.
*/
void MainWindow::setLife(int x)
{
	lives_ = x;
}
