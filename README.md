# 🐍 Snake Game (SFML Library)

From the previous project ([NCurses Snake Game](https://github.com/ekapobTh/Ncurses-Snake-Game)), which led me to upgrade using the SFML library to improve the graphics, mechanics, and structure of the game.

## Controller

🆆🅰🆂🅳 will be the buttons used for control within this game.

* 🆆 - Up
* 🅰 - Left
* 🆂 - Down
* 🅳 - Right

## In-Game Componenet

1. Current Level (Currently 2 levels)
2. Eaten fruit amount (Reset on level changed)
3. Game Title
4. Score
5. Wall
6. Fruit
7. Snake

From these components, you can relate it to the image below in orderly.

![game component screenshot](https://drive.google.com/uc?export=view&id=1QuvXG1DKAD9yteMLdLJ_Barjyg11Qjo-)

## How to play it?

1. When the game start use the controller buttons to control the snake
2. Collect fuit as much as you can.
   * They will respawn at the new position when you collect them.
   * Every time you collect them, the snake's tail will get longer.
4. Be careful of collisions with Wall and Snake tail.
5. If you collect the certain about of fruit the level will change.

## Sample Gameplay

<img src="/content/Snake Game gameplay.gif?raw=true">
