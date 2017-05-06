#ifndef __TRACZS_FUNCTIONS__
#define __TRACZS_FUNCTIONS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#define player "@"

typedef struct rooms_
{
    int y;
    int x;
    //declaring ints for parsing
    int doorY[5];
    int doorX[5];
    int heroX;
    int heroY;
    int stairDX[10];
    int stairDY[10];
    int stairUX[10];
    int stairUY[10];
    int sGoldy[10];
    int sGoldx[10];
    int bGoldx;
    int bGoldy;
    int cWepx[10];
    int cWepy[10];
    int rWepy;
    int rWepx;
    int wMonx[10];
    int wMony[10];
    int equipY[10];
    int equipX[10];
    int sMony[10];
    int sMonx[10];
    int poty[10];
    int potx[10];
}room;

typedef struct Hero_
{
    int attack;
    int defence;
    int inventory;
    int commonWep;
    int rareWep;
    int equipment;
    int gold;
    int potion;
    int health;
    int commonCounter;
    int rareCounter;
    int equipCounter;
}Hero;

typedef struct Aquator_
{
    int attack;
    int health;
    int speed;
}Aquator;

typedef struct Bat_
{
    int attack;
    int health;
    int speed;
}Bat;

typedef struct Snake_
{
    int attack;
    int health;
    int speed;
}Snake;

typedef struct Zombie_
{
    int attack;
    int health;
    int speed;
}Zombie;

typedef struct Troll_
{
    int attack;
    int health;
    int speed;
}Troll;


/**
* getSpec
* parses the file and convests the string to integers where applicable and stores it into a struct
* IN: the argc file, hero struct
* OUT: void
* POST: May not parse the file correctly.
* ERROR: If room size would be greater than 18x23, it would screw up the whole program.
*/
void getSpec(char* file,Hero* heroman);

/**
* startGame
* initializes screen for ncurses and calls on the drawMap function
* IN:
* OUT: void
* POST: initializes the screen.
* ERROR: not that I know of
*/
void startGame();

/**
* inGame
* runs a loop that takes user input and calls moveDude to move the character until user quits
* IN: hero struct and every monster struct
* OUT: void
* ERROR: not that I know of
*/
void inGame(Hero* heroman,Aquator* aquator, Bat* bat, Snake* snake, Zombie* zombie, Troll* troll);

/**
* moveDude
* checks what the user presses and calls on checkMove to see if it can call on moveGuy
* IN: current X position, current Y position, user input, hero struct and monster structs and a counter for your moves to be used for the monster patrol.
* OUT: void
* ERROR: only works with wasd keys
*/
void moveDude(int curY, int curX, char userPress,Hero* heroman,Aquator* aquator, Bat* bat, Snake* snake, Zombie* zombie, Troll* troll, int round);

/**
* moveGuy
* moves player by one spot and leaves a "." in the spot it left.
* IN: new x position, new y position
* OUT: void
* ERROR: will not move you correctly if you are going into a border of the window.
*/
void moveGuy(int newY, int newX);

/**
* hallMove
* moves player by one spot and leaves a "#" in the spot it left.
* IN: new x position, new y position
* OUT: void
* ERROR: will not move you correctly if you are going into a border of the window.
*/
void hallMove(int newY, int newX);

/**
* doorMove
* moves player by one spot and leaves a "+" in the spot it left.
* IN: new x position, new y position
* OUT: void
* ERROR: will not move you correctly if you are going into a border of the window.
*/
void doorMove(int newY, int newX);

/**
* checkMove
* checks if the spot in front is an obstacle and returns values based on that.
* IN: next y value, next x value.
* OUT: returns 0 through 9
* ERROR: not that I know of
*/
int checkMove(int nextY, int nextX,Hero* heroman);

/**
* drawMap
* draws out the rooms and part of the hallways.
* IN: room number, room struct containing many x and y coordinates
* OUT: draws the map out
* ERROR:
*/
void drawMap(int roomnum,room theRooms);

/**
* randMonster
* generates the random weak monster
* OUT: returns the letter associated to the monster
* ERROR:
*/
char randMonster();

/**
* initHero
* initializes the hero stats
* IN: Hero struct
* OUT: hero struct
*/
void initHero(Hero* heroman);

/**
* statusBar
* generates the status bar at the bottom
* IN: Hero struct
* OUT: prints stats on bar
*/
void statusBar(Hero* heroman);

/**
* drawHall
* generates the hallways from the door locations
* 
*/
void drawHall(room theRooms);

/**
* finish
* clears screen and shows endgame stats
* IN: hero struct
* OUT: endgame stats
* ERROR: does not necessarily end the game
*/
void finish(Hero* heroman);

/**
* initmonster
* initializes all monster stats to appropriate struct
* IN: all of the monster structs
* OUT: all the updated monster structs
*/
void initMonster(Aquator* aquator, Bat* bat, Snake* snake, Zombie* zombie, Troll* troll);

/**
* fightA
* the fight between hero and aquator
* IN: hero struct aquator struct
* OUT: updated hero struct and aquator struct
*/
void fightA(Hero* heroman, Aquator* aquator);

/**
* fightB
* the fight between hero and bat
* IN: hero struct bat struct
* OUT: updated hero struct and bat struct
*/
void fightB(Hero* heroman, Bat* bat);

/**
* fightS
* the fight between hero and snake
* IN: hero struct snake struct
* OUT: updated hero struct and snake struct
*/
void fightS(Hero* heroman, Snake* snake);

/**
* fightZ
* the fight between hero and Zombie
* IN: hero struct zombie struct
* OUT: updated hero struct and zombie struct
*/
void fightZ(Hero* heroman, Zombie* zombie);

/**
* fightT
* the fight between hero and troll
* IN: hero struct troll struct
* OUT: updated hero struct and troll struct
*/
void fightT(Hero* heroman, Troll* troll);

/**
* heroStatus
* checks if the hero's health is above 0
* IN: hero struct
* OUT:if health is under 0 finish(); is called
*/
void heroStatus(Hero* heroman);

/**
* patrol
* makes the monsters move
* ERROR: sometimes enemies spontaneously combust, especially bats
*/
void patrol();

#endif