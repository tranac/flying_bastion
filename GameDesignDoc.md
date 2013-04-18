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

**Data Members**

* `int x_`
> X coordinate of the item relative to the game screen.

* `int y_`
> Y coordinate of the item relative to the game screen.

* `int vx_`
> Velocity of the x coordinate. Item will move this many pixels each time `move()` is called.

* `int vy_`
> Velocity of the y coordinate. Item will move this many pixels each time `move()` is called.

* `QPixMap* pic_`
> QPixMap for the graphic of the item. 

**Member Methods**

* `Item(int x, int y, int vx, int vy, QPixMap* pic)`
> Default constructor.

* `virtual move()`
> Virtual move function. Changes the item position.

### `VerticalWall`
One of the obstacles. Moves up and down a portion of the screen at a constant rate. Does not move horizontally (except as the screen moves horizontally).

**Data Members**

* `ItemName`
>Text

**Member Methods**

* `VerticalWall(int x, int y, int vx, int vy, QPixMap* pic)`
> Default constructor.

* `move()`
> Changes the item position.

### `Bullet` \ or `FireBall`
One of the obstacles. Moves horizontally at a rate faster than the screen scrolls. Vertical position is randomized and does not change as the object moves.

**Data Members**

>Text

**Member Methods**

* `Bullet(int x, int y, int vx, int vy, QPixMap* pic)` \ `FireBall(int x, int y, int vx, int vy, QPixMap* pic)`
> Default constructor.

* `move()`
> Changes the item position.

### `Wind` / `Whirlpool` thing
One of the obstacles. Does not move horizontally or vertically (besides moving with the scrolling screen). It does however mover in a stationary clockwise fashion. Covers a larger area than the other obstacles.

**Data Members**

`ItemName`
>Text

**Member Methods**

`Wind(int x, int y, int vx, int vy, QPixMap* pic)`
> Default constructor.

`move()`
> Changes the item position.

### `Item 4`


**Data Members**

* `ItemName`
>Text

**Member Methods**

* `(int x, int y, int vx, int vy, QPixMap* pic)`
> Default constructor.

* `move()`
> Changes the item position.

### `Gem`
Bonus item in the game. Appears sporadically and moves in a zig-zag path across the screen (moves vertically and horizontally). 

**Data Members**

* `ItemName`
>Text

**Member Methods**

* `Gem(int x, int y, int vx, int vy, QPixMap* pic)`
> Default constructor.

* `move()`
> Changes the item position.

### `Player`
Player is the user's avatar. 

**Data Members**

* `QPixMap* player_`
> Image of the player. Contains

**Member Methods**

* `Player()`

## Gameplay
This game is a side-scrolling "flying" game similar to the well-known helicopter game. The player's avatar starts halfway (on the vertical scale) up the screen on the left side. If the mouse is not clicked, the player will fall to the bottom of the screen (same y-coordinate) at a constant rate. If the mouse button is clicked, the player will start to ascend. The longer the button is clicked, the higher they rise. As soon as the mouse is release, the player starts to fall again.

The user must avoid all of the obstacles which include moving platforms, bullets/fireballs (not sure which yet), and _____________. They can also pick up gems. If the user's avatar comes in contact with any of these items, it counts as a hit.

### Levels
There are 5 levels. Each level lasts 30 seconds (tentatively). The screen (and the obstacles) start moving faster at the beginning of each level. The upper levels may also an influx of obstacles.

### Scoring
Score will increase at a constant rate the longer the player stays in the game. It's equivalent to the distance that the player flies. Gems are worth bonus points.

### Lives
The user will have 3 initial lives. Every time the user hits an obstacle, they lose a life. The obstacle will disappear and the avatar will flash, but the game will continue on. There are no ways to gain additional lives. Scores will accumulate for the 3 lives. Once a player loses all three lives, the game ends.

### Power-Ups
There is only one power-up, a shield that allows the user to take one hit without losing a life.

## Layout
See attached photo. 

New items will be entering the screen from the right side and exit from the left side.


