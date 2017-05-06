//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ncurses.h>
#include "functions.h"

int main(int argc, char* argv[])
{
    Hero * heroman;
    heroman = malloc(sizeof(Hero)*1);
    Aquator * aquator;
    Bat * bat;
    Snake * snake;
    Zombie * zombie;
    Troll * troll;
    aquator = malloc(sizeof(Aquator));
    bat = malloc(sizeof(Bat));
    snake = malloc(sizeof(Snake));
    zombie = malloc(sizeof(Zombie));
    troll = malloc(sizeof(Troll));
    char* file;
    file = argv[1];
    initMonster(aquator, bat, snake, zombie, troll);
    initHero(heroman);
	getSpec(file,heroman);
	inGame(heroman,aquator, bat, snake, zombie, troll);
	endwin();
	free(heroman);
	free(bat);
	free(snake);
	free(zombie);
	free(troll);
    return 0;
}