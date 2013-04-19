#Game Design Document for PA5 & PA6

## Purpose/Overview

The purpose of these programming assignments is to make a game using QT. The game must including moving objects and will be implemented using timers, GUI input classes, and QT widgets.

## Requirements

* Must have at least 5 different items in the game, 4 of which must be moving.
* Items must be represented by different classes, and must be stored in a templated data structure, STL container, or QT container.
* New items show up randomly at different times and intervals.
* Users can start, pause, and quit the game.
* Users have a username, a score displayed, and a finite amount of lives.
* Game should speed up as time elapses until its too hard for a human to play.

## Five Moving Items / Classes

### `Item`
Abstract base class that all of the game items inherits from.

#### Data Members

`int x_`

X coordinate of the item relative to the game screen.

`int y_`

Y coordinate of the item relative to the game screen.

`int vx_`

Velocity of the x coordinate. Item will move this many pixels each time `move()` is called.

`int vy_`

Velocity of the y coordinate. Item will move this many pixels each time `move()` is called.

`QPixMap* pic_`

QPixMap for the graphic of the item. 

#### Member Methods

`Item(int x, int y, int vx, int vy, QPixMap* pic)`
Default constructor.

`virtual move()`
Virtual move function. Changes the item position.

### Item One: `Platform`
Inherits from `Item`. One of the obstacles. Vertical wall that moves up and down a portion of the screen at a constant rate. Does not move horizontally (except as the screen moves horizontally).
obstacles.

#### Data Members

Inherited members from `Item`.

#### Member Methods

`Platform(int y, int vx, int vy, QPixMap* pic)`
Default constructor. Initial `x_` is always the right edge of the screen. `vx_` will be the speed of the background.

`move()`
Changes the item position.

### Item Two: `Arrow`
Inherits from `Item`. One of the obstacles. Moves horizontally at a rate faster than the screen scrolls. Vertical position is randomized and does not change as the object moves.
obstacles.

#### Data Members

Inherited members from `Item`.

#### Member Methods

`Arrow(int y, int vx, QPixMap* pic)`
Default constructor. Initial `x_` is always the right edge of the screen. `vy_` is 0.

`move()`
Changes the item position.

### Item Three: `Wind`
Inherits from `Item`. One of the obstacles. Does not move horizontally or vertically (besides moving with the scrolling screen). It does however mover in a stationary clockwise fashion. Covers a larger area than the other obstacles.

#### Data Members

Inherited members from `Item`.

#### Member Methods

`Wind(int x, int y, int vx, QPixMap* pic)`
Default constructor. Initial `x_` is always the right edge of the screen. `vy_` is 0. `vx_` moves at the same speed as the screen. The clockwise motion will be made by editing the `pic` of the wind.

`move()`
Changes the item position.

### `Dragon`
Inherits from `Item`. One of the obstacles. Once the user reaches level 3 of 5, there is a chance of a dragon appearing. This dragon is the same size as `Wind` and behaves in the same fashion. However, a dragon will kill you right away, no matter how many lives you have left.

#### Data Members

Inherited members from `Item`.

#### Member Methods

`Dragon(int x, int y, int vx, QPixMap* pic)`
Default constructor. Initial `x_` is always the right edge of the screen. `vy_` is 0. `vx_` moves at the same speed as the screen.

`move()`
Changes the item position.

### `Gem`
Inherits from `Item`. Bonus item in the game. Appears sporadically and moves in straight line at a faster speed than the screen.

#### Data Members

Inherited members from `Item`.

#### Member Methods

`Gem(int x, int y, int vx, QPixMap* pic)`
Default constructor. Initial `x_` is always the right edge of the screen. `vy_` is 0. `vx_` moves at the same speed as the screen.

`move()`
Changes the item position.

### `Player`
Inherited from `Item`. Player is the user's avatar. 

#### Data Members

`QPixMap* player_`
Image of the player.

`int lives_`
Number of lives the user has. Initialized to 3 and decreased by 1 each time the player hits an obstacle.

#### Member Methods

`Player()`
Default constructor.

`move()`
Changes the player's position. If mouse is clicked, player is moved in a positive vertical direction. Otherwise it moves down.

## Gameplay
This game is a side-scrolling "flying" game similar to the well-known helicopter game. The player's avatar starts halfway (on the vertical scale) up the screen on the left side. If the mouse is not left-clicked, the player will fall to the bottom of the screen (same y-coordinate) at a constant rate. If the mouse button is clicked, the player will start to ascend. The longer the button is clicked, the higher they rise. As soon as the mouse is release, the player starts to fall again.

The user must avoid all of the obstacles which include moving platforms, arrows, and wind gusts. They can also pick up gems. If the user's avatar comes in contact with any of these items, it counts as a hit.

### Levels
There are 5 levels. Each level lasts 30 seconds (tentatively). The screen (and the obstacles) start moving faster at the beginning of each level. The upper levels also increase the frequency of obstacles. Starting level 3, there is a possibilty of a dragon appearing, which can kill the user right away.

### Scoring
Score will increase at a constant rate the longer the player stays in the game. It's equivalent to the distance that the player flies. Gems are worth bonus points. Score cannot decrease.

### Lives
The user will have 3 initial lives. Every time the user hits an obstacle, they lose a life. The obstacle will disappear and the avatar will flash, but the game will continue on. If the user hits the top or bottom edge of the screen, they lose a life. There are no ways to gain additional lives. Scores will accumulate for the 3 lives. Once a player loses all three lives, the game ends.

There will be a `int` value called `lives_` in `player` which will be decreased each time a user loses a life.

## Layout
There will be a start screen, a gameplay screen, and a finished screen.

### Start Screen
Includes the game name, a text box to enter a username, a start button, and a quit button. If the user does not enter a username, it defaults to 'User'. The quit button closes the program, and the start button will begin the game and transition to the gameplay screen.

### Gameplay Screen
New items will be entering the screen from the right side and exit from the left side. The player's avatar stays about a third of the way from the left of the screen and moves only in the vertical direction. Lives are displayed in the top right corner.

#### Toolbar
There is a toolbar at the bottom of the gameplay windowthat shows the user's name and score. It also contains two buttons, one start/pause button and one quit button. 

### Finish Screen
Once the player loses all three lives, the game switches to the finish screen. The screen shows the player's final score and has two buttons, one to start a new game and one to quit.
