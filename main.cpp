#include "main.h"
#include <iostream>

/**
Constructor. Creates the game window and the initial toolbar and welcome screen. Sets intial values. Creates Pixmap images for items. 
*/
MainWindow::MainWindow()
{
  //set initial variables
	started = false;
	finished = true;
	score_ = 0;
	lives_ = 0;
	executions = 0;
	speed = 15;
	canCollide = true;
	len = 3500;
	level = 1;
	
  //create Pixmap images
  	as1 = new QPixmap("images/airsoldier1.png","png");
  	as2 = new QPixmap("images/airsoldier2.png","png");
	as3 = new QPixmap("images/airsoldier3.png","png");
  	at = new QPixmap("images/aquatank.png","png");
  	g1 = new QPixmap("images/gargoyle1.png","png");
  	g2 = new QPixmap("images/gargoyle2.png","png");
  	rn1 = new QPixmap("images/rednocturne1.png","png");
  	rn2 = new QPixmap("images/rednocturne2.png","png");
	tm1 = new QPixmap("images/trickmaster1.png","png");
	tm2 = new QPixmap("images/trickmaster2.png","png");
  	ts1 = new QPixmap("images/tornadostep1.png","png");
  	ts2 = new QPixmap("images/tornadostep2.png","png");
	w1 = new QPixmap("images/wyvern1.png","png");
	w2 = new QPixmap("images/wyvern2.png","png");
  	wm1 = new QPixmap("images/whitemushroom1.png","png");
  	wm2 = new QPixmap("images/whitemushroom2.png","png");
  	l = new QPixmap("images/life.png","png");
  	l1 = new QPixmap("images/level1.png","png");
	l2 = new QPixmap("images/level2.png","png");
	l3 = new QPixmap("images/level3.png","png");
  	bgs = new QPixmap("images/startbackground.png","png");
  	
  //create overall layout
	window = new QWidget;
	setCentralWidget(window);
	layout = new QVBoxLayout(window);
	window->setLayout(layout);

  //create options toolbar 
	options = new QHBoxLayout();
	layout->addLayout(options);
  //create start button
  	start = new QPushButton("Start");
	options->addWidget(start);
	QObject::connect(start,SIGNAL(clicked()),this,SLOT(startGame()));
  //create pause button
  	pause = new QPushButton("Pause");
  	options->addWidget(pause);
  	QObject::connect(pause,SIGNAL(clicked()),this,SLOT(pauseGame()));
  //create quit button
	quit = new QPushButton("Quit");
	options->addWidget(quit);
	QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
  //create help button
  	help = new QPushButton("Help?");
  	options->addWidget(help);
  	QObject::connect(help,SIGNAL(clicked()),this,SLOT(toggleHelp()));
  //create invincibility option
  	invincible = new QRadioButton("Invincible Mode?",this);
  	options->addWidget(invincible);
  //create mute button
  	mute = new QPushButton("Mute");
  	options->addWidget(mute);
  	QObject::connect(mute,SIGNAL(clicked()),this,SLOT(toggleSound()));
  		
  //create gamespace
  	gameplay = new QHBoxLayout();
	layout->addLayout(gameplay);
	
	scene = new QGraphicsScene();
	scene->setSceneRect(0,0,650,350);
	view = new QGraphicsView(scene);
	view->setFixedSize(675,375);
	QColor c(Qt::black);
	QBrush b(c,*bgs);
	view->setBackgroundBrush(b);
// 	layout->addWidget(view);
	gameplay->addWidget(view);
  //create name input form
	name_ = new QLineEdit();
	name_->setGeometry(300,250,190,30);
 	scene->addWidget(name_);
 	 	
  //create start/gameover screen
  	message = new Message();
  	message->setStart();
  	scene->addItem(message);
  
  //create help screen
  	helpscreen = new Help();
  	scene->addItem(helpscreen);
  	helpscreen->hide();

  //create timer
  	timer = new QTimer();
	timer->setInterval(speed);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(handleTimer()));
	
  //create audio
  	audio = new Audio();
  	audio->play();
  	
  //create high scores
  	scores = new Score();
  	scene->addWidget(scores);
  	gameplay->addWidget(scores);
  	
  //create invincible mode label
  	i = new QLabel("Invincible Mode!");
	scene->addWidget(i);
	i->setAttribute(Qt::WA_TranslucentBackground);
	i->setGeometry(0,-3,300,10);
	i->setWindowFlags(Qt::WindowStaysOnTopHint);
	i->hide();
}

/**
Deletes the timer. 
*/
MainWindow::~MainWindow()
{
	audio->stop();
	delete audio;
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
	//create initial gameplay items if it's a new game
	if(!started)
	{
		//grab username
		QString n = name_->text();
		//if empty, the game won't start;
		if(n == "")
			return;
		
		//create username and score output
//		n = n + " Score";
		s = new QFormLayout();
 	 	score = new QLineEdit(QString::number(score_));
 	 	score->setReadOnly(true);
  		score->setFixedWidth(100);
  		s->addRow(n,score);
  		options->addLayout(s);
  		options->setStretch(3,0.5);
  		
		//make the name input form invisible and unaccessible
		name_->setEnabled(false);
		name_->setHidden(true);
		name_->setReadOnly(true);
				
		//create scrolling background
		background = new Background(0,l1,l2,l3);
		background2 = new Background(999,l1,l2,l3);
		scene->addItem(background);
		scene->addItem(background2);
		
		//hide invincible mode selection
		invincible->hide();
		//create invincibility mode notifier if invincibility mode is checked
		if(invincible->isChecked())
			i->show();
		
		//set flag
		started = true;
	
		//create points label
		points = new QLabel("Bonus Points!");
		scene->addWidget(points);
		points->setAttribute(Qt::WA_TranslucentBackground);
		points->setGeometry(567,15,100,10);
		points->setWindowFlags(Qt::WindowStaysOnTopHint);
		
		//create levels label
		lvl = new QLabel("Level One");
		scene->addWidget(lvl);
		lvl->setAttribute(Qt::WA_TranslucentBackground);
		lvl->setGeometry(573,0,100,10);
		lvl->setWindowFlags(Qt::WindowStaysOnTopHint);
	}
	else
	{
		//reset values
		timer->stop();
		speed = 15;
		timer->setInterval(speed);
		score_ = 0;
		executions = 0;
		c = 0;
		canCollide = true;
		len = 3500;
		
		//reset pause button
		pause->setText("Pause");
		
		//delete items if not already deleted
		if(!finished)
			{
			//delete player
			scene->removeItem(player);
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
	//hide start/gameover screen
	message->hide();
	
	//hide & reset help screen
	helpscreen->hide();
	help->setText("Help?");
	
	//set level
	level = 1;
	lvl->setText("Level One");
	lvl->show();

	//set level 1 image and show moving background
	background->setImage(level);
	background->setImage(level);
	background->show();
	background2->show();
	
	//create new player
	player = new Player(this);
	scene->addItem(player);
	
	//create lives
	lives_ = 3;
	int x = 5;	//initial position
	for(int i=0;i<3;i++)
	{
		life = new Life(x,5,l);
		scene->addItem(life);
		lives.push_back(life);
		x = x+15;
	}
		
	//hide points label
	points->hide();
		
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

/** Mutes and unmutes the game music. Handled in Audio. Only thing that needs to be changed here is the button text. */
void MainWindow::toggleSound()
{
	//set button text
	if(audio->togglePlaying())
		mute->setText("Unmute");
	else
		mute->setText("Mute");
}

/** Shows the help screen. If the screen is already shown, hide the help screen. */
void MainWindow::toggleHelp()
{
	//pause/continue game if started
	if(started && !finished)
	{
		if(timer->isActive())
		{
			timer->stop();
			//hide gameplay screen
			background->hide();
			background2->hide();
			player->hide();
			lvl->hide();
			for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
			{
				Item* temp = *it;
				temp->hide();
			}
		
			for(QVector<Life*>::iterator it = lives.begin(); it != lives.end(); ++it)
			{
				Life* temp = *it;
				temp->hide();
			}
		}
		else
		{
			timer->start();
			//show gameplay screen
			background->show();
			background2->show();
			player->show();
			lvl->show();
			for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
			{
				Item* temp = *it;
				temp->show();
			}
	
			for(QVector<Life*>::iterator it = lives.begin(); it != lives.end(); ++it)
			{
				Life* temp = *it;
				temp->show();
			}
		}
	}
	
	if(helpscreen->isVisible())
	{
		//hide help screen
		helpscreen->hide();
		help->setText("Help?");
	}
	else
	{
		//show help screen
		helpscreen->show();
		help->setText("Hide.");
	}
}

/**
Handles the timer every time it timesout. If invincible mode is checked, no collisions will be checked. Otherwise it will first check against the walls and then against the items.

If a player holds no lives, endGame() is called. If not, Items are then moved.

handleTimer() also checks if new enemies should be spawned or if the game should be sped up.
*/
void MainWindow::handleTimer()
{
	//end buffer if necessary
	if(!canCollide && c == len/70)
	{
		canCollide = true;
		c = 0;
		player->show();
		//hide points if shown
		points->hide();
	}
	//flash player if collision buffer is still on
	else if(!canCollide)
	{
		if(c % 2)
			player->hide();
		else
			player->show();
		//increase count
		c++;
	}
	
	//check collisions if buffer is not set
	if(canCollide)
	{
		//check boundaries
		player->collide();
		//check enemies
		for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
		{
		  Item* temp = *it;
		  temp->collide();
		}
	}

	//check if player is dead
	if(!lives_)
	{
		endGame();
		return;
	}
	
	//check if items left the scene
	deleteEnemies();
	
	//move background
	background->move();
	background2->move();
	
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
	if(!(executions % 100))
	{
		createEnemies();
	}

	//increase score and executions
	score_++;
	score->setText(QString::number(score_));
	executions++;
	
	//check if level up to two
	if(score_ == 3000)
	  {
	    level++;
	    timer->setInterval(7);
	    background->setImage(level);
	    background2->setImage(level);
	    lvl->setText("Level Two");
	  }
	//check if level up to three
	if(score_ == 10000)
	  {
	    level++;
	    background->setImage(level);
	    background2->setImage(level);
	    lvl->setText("Level Three");
	    //set label color
	    QColor c(Qt::black);
	    QPalette p(c);
	    lvl->setPalette(p);
	  }
}

/**
Creates a new item. The new item is randomized. For WhiteMushrooms and TornadoSteps, they must also pass a second randomized statement.
*/
void MainWindow::createEnemies()
{
	//randomly create enemies
	srand(time(0));
	int a = rand() % 9;
	int b = rand() % 280;
	
/*	switch(a)
	{
		//create red nocture
		case 1:
		{
			newItem = new RedNocturne(b,rn1,rn2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
		//create aquatank
		case 2:
		{
			newItem = new Aquatank(b,at,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
		//chance to create white mushroom
		case 3:
		{
			int ch = rand() % 3;
			//create gem
			if(!ch)
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
			int ch = rand() % 3;
			//create gem
			if(!ch)
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
			newItem = new AirSoldier(as1,as2,as3,player,this);
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
		//chane to create trickmaster
		case 7:
		{
			int ch = rand() % 3;
			if(!ch)
			{
				newItem = new Trickmaster(tm1,tm2,player,this);
				scene->addItem(newItem);
				items.push_back(newItem);
			}
			return;
		}
		//create wyvern
		case 8:
*/		{
			newItem = new Wyvern(w1,w2,player,this);
			scene->addItem(newItem);
			items.push_back(newItem);
			return;
		}
//	}
}

/**
Ends the game. Stops the timer and sets the finished flag. Removes and deletes the player and the items. Also sets the GameOver message.
*/
void MainWindow::endGame()
{
	//stop timer and set flags
	timer->stop();
	points->hide();
	lvl->hide();
	i->hide();
	finished = true;

	//delete player 
	scene->removeItem(player);
	delete player;

	//delete lives if any are left
	QVector<Life*>::iterator it = lives.begin();
	while(it != lives.end())
	{
		Life* temp = *it;
		scene->removeItem(temp);
		delete temp;
		++it;
	}
	lives.clear();

	//delete remaining items
	for(QVector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		Item* temp = *it;
		scene->removeItem(temp);
		delete temp;
	}
	items.clear();

	//set gameover message
	message->setEnd();
	message->show();
	
	//hide moving background
	background->hide();
	background2->hide();
	
	//add high score
	string n = name_->text().toUtf8().constData();
	std::cout << n << " " << score_ << std::endl;
	scores->add(score_,n);
}

/**
Called when a player loses a life. Decreases the count and deletes a Life image in the corner. Starts the canCollide buffer so that a user can avoid the object that just killed them. If invincibility mode is on, no lives are lost but the player still flashes.
*/
void MainWindow::loseLife()
{
	//only delete lives if not invincible
	if(!invincible->isChecked())
	{
	  //check level first
	  if(level == 3)
	    {
	    setLife(0);
	    
	    //clear life images
	    QVector<Life*>::iterator it = lives.begin();
	    while(it != lives.end())
	      {
                Life* temp = *it;
                scene->removeItem(temp);
		delete temp;
                ++it;
	      }
	    lives.clear();
	    }
	  else
	    {
		lives_--;
		life = lives.back();
		scene->removeItem(life);
		delete life;
		lives.pop_back();
	    }
	}
	player->hide();
	c = 0;
	canCollide = false;
}

/**
Called by WhiteMushroom. Gives the user an additional life. Only gives an extra life if the player is not playing invincibility mode.
*/
void MainWindow::gainLife()
{
	//adds a new life
	if(!invincible->isChecked())
	{
		lives_++;
		Life* end = lives.back();
		life = new Life((end->getX()+15),5,l);
		scene->addItem(life);
		lives.push_back(life);
	}
	//set flags
	c = 0;
	canCollide = false;
}

/**
Called by TornadoStep. Gives the user 100 additional points.
*/
void MainWindow::gainPoints()
{
	//set flags
	c = 0;
	canCollide = false;
	
	//update score
	score_ = score_ + 100;
	score->setText(QString::number(score_));
	
	//show message
	points->show();
}

/**
Iterates through the vector of items. If the item has moved past the left boundary, it is deleted.
*/
void MainWindow::deleteEnemies()
{
	QVector<Item*>::iterator it = items.begin();
	
	//walks through list of items
	while(it != items.end())
	{
		Item* temp = *it;
		if(temp->getX() <= -20)	//deletes item if item is off screen
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
Called by Aquatank. Sets the number of lives to x. Does nothing if invincible
*/
void MainWindow::setLife(int x)
{
	//set flags
	c = 0;
	canCollide = false;
	
	if(!invincible->isChecked())
		lives_ = x;
}
