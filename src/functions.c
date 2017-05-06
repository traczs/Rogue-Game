#include "functions.h"

void getSpec(char* file,Hero* heroman)
{
    char string[256] = "";
    char newString[256] = "";
    int roomNum = 0;
    //array of structs for the rooms
    room * theRooms;
    theRooms = malloc(sizeof(room)*6);
    //Hero * heroman;
    //heroman = malloc(sizeof(Hero));

    FILE* specFile;
    specFile = fopen(file,"r");

    while(fgets(string,256,specFile)!=NULL)
    {
        //variables
        char* str;
        char* y;
        char* x;
        int doorNum = 0;
        char* door;
        char newDoor[2] = "";
        char* hero;
        char heroY[2] = "";
        char heroX[2] = "";
        char* stairDown;
        char stairDX[2] = "";
        char stairDY[2] = "";
        int stairdNum = 0;
        char* stairUp;
        char stairUX[2] = "";
        char stairUY[2] = "";
        int stairuNum = 0;
        char* sGold;
        char sGoldy[2] = "";
        char sGoldx[2] = "";
        int sGoldnum = 0;
        char* bGold;
        char bGoldy[2] = "";
        char bGoldx[2] = "";
        char* cWep;
        char cWepx[2] = "";
        char cWepy[2] = "";
        int cWepn = 0;
        char* rWep;
        char rWepy[2] = "";
        char rWepx[2] = "";
        char* wMon;
        char wMony[2] = "";
        char wMonx[2] = "";
        int wMonn = 0;
        char* equip;
        char equipY[2] = "";
        char equipX[2] = "";
        int eqN = 0;
        char* sMon;
        char sMony[2] = "";
        char sMonx[2] = "";
        int sMonn = 0;
        char* pot;
        char poty[2] = "";
        char potx[2] = "";
        int potN = 0;

        //ydimension
        y = strtok(string,"X");
        theRooms[roomNum].y = atoi(y);
        //x dimension
        x = strtok(NULL," ");
        theRooms[roomNum].x = atoi(x);

        str = strtok(NULL,"\n");
        strcpy(newString,str);

        for(int i=0;i<=strlen(newString)+1;i++)
        {
        	i=0;
            //doing the math for the door coordinates
            if(newString[0] == 'd')
            {
                i++;
                if(newString[1] == 'n')
                {
                    if(roomNum <= 2)
                    {
                        theRooms[roomNum].doorY[doorNum] = 3;
                    }
                    else if (roomNum>=3)
                    {
                        theRooms[roomNum].doorY[doorNum] = 24;
                    }
                    door = strtok(NULL," ");
                    i = i + strlen(door);
                }
                else if(newString[1] == 's')
                {
                    if(roomNum<=2)
                    {
                    	theRooms[roomNum].doorY[doorNum] = theRooms[roomNum].y + 4;
                    }
                    else if(roomNum>=3)
                    {
                        theRooms[roomNum].doorY[doorNum] = theRooms[roomNum].y + 25;
                    }
                   	door = strtok(NULL," ");
                    i = i + strlen(door);
                }
                else if(newString[1] == 'e')
                {
                    if(roomNum==0||roomNum==3)
                    {
                        theRooms[roomNum].doorX[doorNum] = theRooms[roomNum].x + 3;
                    }
                    else if(roomNum==1||roomNum==4)
                    {
                        theRooms[roomNum].doorX[doorNum] = 29 + theRooms[roomNum].x;
                    }
                    else if(roomNum==2||roomNum==5)
                    {
                        theRooms[roomNum].doorX[doorNum] = 55 + theRooms[roomNum].x;
                    }
                    door = strtok(str," ");
                    i = i + strlen(door);
                }
                else if(newString[1] == 'w')
                {
                    if(roomNum==0||roomNum==3)
                    {
                        theRooms[roomNum].doorX[doorNum] = 2;
                    }
                    else if(roomNum==1||roomNum==4)
                    {
                        theRooms[roomNum].doorX[doorNum] = 28;
                    }
                    else if(roomNum==2||roomNum==5)
                    {
                        theRooms[roomNum].doorX[doorNum] = 54;
                    }
                    door = strtok(NULL," ");
                    i = i + strlen(door);
                }
                memset(newDoor,0,strlen(door));
                for(int w = 0; w<strlen(door)-2;w++)
                {
        	        newDoor[w] = door[w+2];
                }
                //part 2 of door math
                if((door[1] == 'n')||(door[1] == 's'))
                {
                    if(roomNum==0||roomNum==3)
                    {
                        theRooms[roomNum].doorX[doorNum] = atoi(newDoor) + 2;
                    }
                    else if(roomNum==1||roomNum==4)
                    {
                        theRooms[roomNum].doorX[doorNum] = atoi(newDoor) + 28;
                    }
                    else if(roomNum==2||roomNum==5)
                    {
                        theRooms[roomNum].doorX[doorNum] = atoi(newDoor) + 54;
                    }
                }
                else if ((door[1]== 'e')||(door[1]=='w'))
                {
                    if(roomNum<=2)
                    {
                        theRooms[roomNum].doorY[doorNum] = atoi(newDoor) + 3;
                    }
                    else if(roomNum>=3)
                    {
                        theRooms[roomNum].doorY[doorNum] = atoi(newDoor) + 24;
                    }
                }
                doorNum++;
                for(int f = 0; f<strlen(newString);f++)
                {
                    newString[f] = newString[f + strlen(door)+1];
                }
            }
            //hero parsing
            else if(newString[0]=='h')
            {
                hero = strtok(NULL," ");
                int heroCheck = 0;
                while(hero[heroCheck+1] != ',')
                {
                    heroY[heroCheck] = hero[heroCheck+1];
                    heroCheck++;
                }
                i = i + strlen(hero);
                for(int i = 0; i<strlen(hero)-strlen(heroY)-2;i++)
                {
                    heroX[i] = hero[strlen(heroY)+2];
                }
                theRooms[roomNum].heroX = atoi(heroX);
                theRooms[roomNum].heroY = atoi(heroY);
                     for(int i = 0; i<strlen(newString);i++)
                {
                    newString[i] = newString[i + strlen(hero)+1];
                }
            }
            //stairs parsing
            else if(newString[0] == 'z')
            {
                if(strstr(newString," ")!=NULL)
                {
                    stairDown = strtok(NULL, " ");
                    int stairCheck = 0;
                    while(stairDown[stairCheck+1] != ',')
                    {
                        stairDY[stairCheck] = stairDown[stairCheck+1];
                        stairCheck++;
                    }
                    i = i + strlen(stairDown);
                    for(int i = 0; i<strlen(stairDown)-strlen(stairDY)-2;i++)
                    {
                        stairDX[i] = stairDown[strlen(stairDY)+2];
                    }
                    theRooms[roomNum].stairDX[stairdNum] = atoi(stairDX);
                    theRooms[roomNum].stairDY[stairdNum] = atoi(stairDY);
                    stairdNum++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(stairDown)+1];
                    }
                }
                else
                {
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i+1];
                    }
                    int stairCheck = 0;
                    while(newString[stairCheck] != ',')
                    {
                        stairDY[stairCheck] = newString[stairCheck];
                        stairCheck++;
                    }
                    i = i+strlen(newString);
                    for(int i = 0; i<strlen(newString)-strlen(stairDY)-1;i++)
                    {
                        stairDX[i] = newString[strlen(stairDY)+1];
                    }
                    theRooms[roomNum].stairDX[stairdNum] = atoi(stairDX);
                    theRooms[roomNum].stairDY[stairdNum] = atoi(stairDY);
                    stairdNum++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(newString)+1];
                    }
                }
            }
            //stairs parsing
            else if (newString[0] == 'a')
            {
                if(strstr(newString," ") != NULL)
                {
                    stairUp = strtok(NULL, " ");

                    int stairMaster = 0;
                    while(stairUp[stairMaster+1] != ',')
                    {
                        stairUY[stairMaster] = stairUp[stairMaster+1];
                        stairMaster++;
                    }
                    i = i+strlen(stairUp);
                    for(int i = 0; i<strlen(stairUp)-strlen(stairUY)-2;i++)
                    {
                        stairUX[i] = stairUp[strlen(stairUY)+2];
                    }
                    theRooms[roomNum].stairUX[stairuNum] = atoi(stairUX);
                    theRooms[roomNum].stairUY[stairuNum] = atoi(stairUY);
                    stairuNum++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(stairUp)+1];
                    }
                }
                else
                {
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i+1];
                    }
                    int stairMaster = 0;
                    while(newString[stairMaster] != ',')
                    {
                        stairUY[stairMaster] = newString[stairMaster];
                        stairMaster++;
                    }
                    i = i+strlen(newString);
                    for(int i = 0; i<strlen(newString)-strlen(stairUY)-1;i++)
                    {
                        stairUX[i] = newString[strlen(stairUY)+1];
                    }
                    theRooms[roomNum].stairUX[stairuNum] = atoi(stairUX);
                    theRooms[roomNum].stairUY[stairuNum] = atoi(stairUY);
                    stairuNum++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(newString)+1];
                    }
                }
            }
            //small gold parsing
            else if(newString[0] == 'g')
            {
                sGold = strtok(NULL, " ");
                int smallG = 0;
                while(sGold[smallG+1] != ',')
                {
                    sGoldy[smallG] = sGold[smallG+1];
                    smallG++;
                }
                i = i+strlen(sGold);
                for(int i = 0; i<strlen(sGold)-strlen(sGoldy)-2;i++)
                {
                    sGoldx[i] = sGold[strlen(sGoldy)+2];
                }
                theRooms[roomNum].sGoldx[sGoldnum] = atoi(sGoldx);
                theRooms[roomNum].sGoldy[sGoldnum] = atoi(sGoldy);
                sGoldnum++;
                for(int i = 0; i<strlen(newString);i++)
                {
                    newString[i] = newString[i + strlen(sGold)+1];
                }
            }
            //big gold parsing
            else if(newString[0] == 'G')
            {
                if(strstr(newString," ")!= NULL)
                {
                    bGold = strtok(NULL, " ");
                    int bigG = 0;
                    while(bGold[bigG+1] != ',')
                    {
                        bGoldy[bigG] = bGold[bigG+1];
                        bigG++;
                    }
                    i = i+strlen(bGold);
                    for(int i = 0; i<strlen(bGold)-strlen(bGoldy)-2;i++)
                    {
                        bGoldx[i] = bGold[strlen(bGoldy)+2];
                    }
                    theRooms[roomNum].bGoldx = atoi(bGoldx);
                    theRooms[roomNum].bGoldy = atoi(bGoldy);
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(bGold)+1];
                    }
                }
                else
                {
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i+1];
                    }
                    int gold = 0;
                    while(newString[gold] != ',')
                    {
                        bGoldy[gold] = newString[gold];
                        gold++;
                    }
                    i = i+strlen(newString);
                    for(int i = 0; i<strlen(newString)-strlen(bGoldy)-1;i++)
                    {
                        bGoldx[i] = newString[strlen(bGoldy)+1];
                    }
                    theRooms[roomNum].bGoldx = atoi(bGoldx);
                    theRooms[roomNum].bGoldy = atoi(bGoldy);
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(newString)+1];
                    }
                }
            }
            //small weapon parsing
            else if(newString[0] == 'w')
            {
                srand(time(NULL));
                heroman->commonWep = rand()%8+1;
                if(strstr(newString," ")!= NULL)
                {
                    cWep = strtok(NULL, " ");
                    int wepnCheck = 0;
                    memset(cWepy,0,strlen(cWep));
                    while(cWep[wepnCheck+1] != ',')
                    {
                        cWepy[wepnCheck] = cWep[wepnCheck+1];
                        wepnCheck++;
                    }
                    i = i+strlen(cWep);
                    memset(cWepx,0,strlen(cWep));
                    for(int i = 0; i<strlen(cWep)-strlen(cWepy)-2;i++)
                    {
                        cWepx[i] = cWep[i+strlen(cWepy)+2];
                    }
                    theRooms[roomNum].cWepx[cWepn] = atoi(cWepx);
                    theRooms[roomNum].cWepy[cWepn] = atoi(cWepy);
                    cWepn++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(cWep)+1];
                    }
                }
                else
                {
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i+1];
                    }
                    int weapon = 0;
                    memset(cWepy,0,strlen(newString));
                    while(newString[weapon] != ',')
                    {
                        cWepy[weapon] = newString[weapon];
                        weapon++;
                    }
                    i = i+strlen(newString);
                    memset(cWepx,0,strlen(newString));
                    for(int i = 0; i<strlen(newString)-strlen(cWepy)-1;i++)
                    {
                        cWepx[i] = newString[i+strlen(cWepy)+1];
                    }
                    theRooms[roomNum].cWepx[cWepn] = atoi(cWepy);
                    theRooms[roomNum].cWepy[cWepn] = atoi(cWepy);
                    cWepn++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(newString)+1];
                    }
                }
            }
            //rare weapon parse
            else if(newString[0] == 'W')
            {
                srand(time(NULL));
                heroman->rareWep = rand()%5 + 11;
                rWep = strtok(NULL, " ");
                int wpnCheck = 0;
                memset(rWepy,0,strlen(rWep));
                while(rWep[wpnCheck+1] != ',')
                {
                    rWepy[wpnCheck] = rWep[wpnCheck+1];
                    wpnCheck++;
                }
                i = i+strlen(rWep);
                memset(rWepx,0,strlen(rWep));
                for(int i = 0; i<strlen(rWep)-strlen(rWepy)-2;i++)
                {
                    rWepx[i] = rWep[strlen(rWepy)+2];
                }
                theRooms[roomNum].rWepx = atoi(rWepx);
                theRooms[roomNum].rWepy = atoi(rWepy);
                for(int i = 0; i<strlen(newString);i++)
                {
                    newString[i] = newString[i + strlen(rWep)+1];
                }
            }
            //weak monster parse
            else if(newString[0] == 'm')
            {
                if(strstr(newString," ")!= NULL)
                {
                    wMon = strtok(NULL, " ");
                    int monCheck = 0;
                    memset(wMony,0,strlen(wMon));
                    while(wMon[monCheck+1] != ',')
                    {
                        wMony[monCheck] = wMon[i+monCheck+1];
                        monCheck++;
                    }
                    i = i+strlen(wMon);
                    memset(wMonx,0,strlen(wMon));
                    for(int i = 0; i<strlen(wMon)-strlen(wMony)-2;i++)
                    {
                        wMonx[i] = wMon[i+strlen(wMony)+2];
                    }
                    theRooms[roomNum].wMonx[wMonn] = atoi(wMonx);
                    theRooms[roomNum].wMony[wMonn] = atoi(wMony);
                    wMonn++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(wMon)+1];
                    }
                }
                else
                {
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i+1];
                    }
                    int monster = 0;
                    memset(wMony,0,strlen(newString));
                    while(newString[monster] != ',')
                    {
                        wMony[monster] = newString[monster];
                        monster++;
                    }
                    i = i+strlen(newString);
                    //memset(wMonx,0,strlen(newString));
                    for(int i = 0; i<strlen(newString)-strlen(wMony)-1;i++)
                    {
                        wMonx[i] = newString[i+strlen(wMony)+1];
                    }
                    theRooms[roomNum].wMonx[wMonn] = atoi(wMonx);
                    theRooms[roomNum].wMony[wMonn] = atoi(wMony);
                    wMonn++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(newString)+1];
                    }
                }
            }
            //equipment parsing
            else if(newString[0] == 'e')
            {
                srand(time(NULL));
                heroman->equipment = rand()%20;
                equip = strtok(NULL, " ");
                int eqpCheck = 0;
                memset(equipY,0,strlen(equip));
                memset(equipX,0,strlen(equip));
                while(equip[eqpCheck+1] != ',')
                {
                    equipY[eqpCheck] = equip[eqpCheck+1];
                    eqpCheck++;
                }
                i = i+strlen(equip);
                for(int i = 0; i<strlen(equip)-strlen(equipY)-2;i++)
                {
                    equipX[i] = equip[i + strlen(equipY)+2];
                }
                theRooms[roomNum].equipX[eqN] = atoi(equipX);
                theRooms[roomNum].equipY[eqN] = atoi(equipY);
                eqN++;
                for(int i = 0; i<strlen(newString);i++)
                {
                    newString[i] = newString[i + strlen(equip)+1];
                }
            }
            //strong monster parse
            else if(newString[0] == 'M')
            {
                sMon = strtok(NULL, " ");
                int monsCheck =0;
                while(sMon[monsCheck+1] != ',')
                {
                    sMony[monsCheck] = sMon[monsCheck+1];
                    monsCheck++;
                }
                i = i+strlen(sMon);
                for(int i = 0; i<strlen(sMon)-strlen(sMony)-2;i++)
                {
                    sMonx[i] = sMon[i+strlen(sMony)+2];
                }
                theRooms[roomNum].sMonx[sMonn] = atoi(sMonx);
                theRooms[roomNum].sMony[sMonn] = atoi(sMony);
                sMonn++;
                for(int i = 0; i<strlen(newString);i++)
                {
                    newString[i] = newString[i + strlen(sMon)+1];
                }
            }
            //potion parse
            else if(newString[0] =='p')
            {
                if(strstr(newString," ") != NULL)
                {
                    pot = strtok(NULL, " ");
                    int potion = 0;
                    while(pot[potion+1] != ',')
                    {
                        poty[potion] = pot[potion+1];
                        potion++;
                    }
                    i = i+strlen(pot);
                    for(int i = 0; i<strlen(pot)-strlen(poty)-2;i++)
                    {
                        potx[i] = pot[strlen(poty)+2];
                    }
                    theRooms[roomNum].potx[potN] = atoi(potx);
                    theRooms[roomNum].poty[potN] = atoi(poty);
                    potN++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(pot)+1];
                    }
                }
                else
                {
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i+1];
                    }
                    int stairMaster = 0;
                    while(newString[stairMaster] != ',')
                    {
                        poty[stairMaster] = newString[stairMaster];
                        stairMaster++;
                    }
                    i = i+strlen(newString);
                    for(int i = 0; i<strlen(newString)-strlen(poty)-1;i++)
                    {
                        potx[i] = newString[strlen(poty)+1];
                    }
                    theRooms[roomNum].potx[potN] = atoi(potx);
                    theRooms[roomNum].poty[potN] = atoi(poty);
                    potN++;
                    for(int i = 0; i<strlen(newString);i++)
                    {
                        newString[i] = newString[i + strlen(newString)+1];
                    }
                }
            }
            else
            {
                printf("Failed to parse");
            }
        }
        roomNum++;
    }
    /*for(int i = 0; i <6; i++)
    {
    	for(int j = 0; j<4; j++)
    	{
    		printf("%d,",theRooms[i].doorY[j]);
    		printf("%d  ",theRooms[i].doorX[j]);
    	}
    }*/
    startGame();
    for(int i = 0; i<6;i++)
    {
        drawMap(i,theRooms[i]);
        drawHall(theRooms[i]);
    }
    free(theRooms);
    fclose(specFile);
}

void startGame()
{
    int maX;
    int maY;
    initscr();
    noecho();
    cbreak();
    getmaxyx(stdscr,maX,maY);
    mvprintw(3,3,"Max screen is %d : %d.\n Press any button to continue.",maX,maY);
    getch();
    clear();
}

void inGame(Hero* heroman, Aquator* aquator, Bat* bat, Snake* snake, Zombie* zombie, Troll* troll)
{
    int curX;
    int curY;
    char userPress;
    int round;
    round = 0;
    mvaddch(6,6,'@');
    move(6,6);
    curY = getcury(stdscr);
    curX = getcurx(stdscr);
    userPress = getch();
    while(userPress != 'q')
    {
        moveDude(curY,curX,userPress,heroman,aquator,bat,snake,zombie,troll,round);
        curX = getcurx(stdscr);
        curY = getcury(stdscr);
        userPress = getch();
        round++;
        if(round == 4)
        {
            round = 0;
        }
    }
    finish(heroman);
}

void moveDude(int curY, int curX, char userPress,Hero* heroman, Aquator* aquator, Bat* bat, Snake* snake, Zombie* zombie,Troll* troll, int round)
{
    //go left
    if(userPress == 'a')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        move(0,0);
        clrtoeol();
        move(y,x);
        if(checkMove(curY, curX-1,heroman) == 0)
        {
            moveGuy(curY, curX-1);
        }
        else if(checkMove(curY,curX-1,heroman) == 2)
        {
            hallMove(curY,curX-1);
        }
        else if(checkMove(curY,curX-1,heroman) == 3)
        {
            doorMove(curY,curX-1);
        }
        else if(checkMove(curY,curX-1,heroman) == 4)
        {
            finish(heroman);
        }
        else if(checkMove(curY,curX-1,heroman) == 5)
        {
            fightA(heroman,aquator);
            if(aquator->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed an Aquator");
                move(y,x);
                moveGuy(curY, curX-1);
                aquator-> health = 5;
            }
        }
        else if(checkMove(curY,curX-1,heroman) == 6)
        {
            fightB(heroman,bat);
            if(bat->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Bat");
                move(y,x);
                moveGuy(curY, curX-1);
                bat-> health = 2;
            }
        }
        else if(checkMove(curY,curX-1,heroman) == 7)
        {
            fightS(heroman,snake);
            if(snake->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Snake");
                move(y,x);
                moveGuy(curY, curX-1);
                snake-> health = 5;
            }
        }
        else if(checkMove(curY,curX-1,heroman) == 8)
        {
            fightZ(heroman,zombie);
            if(zombie->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Zombie");
                move(y,x);
                moveGuy(curY, curX-1);
                zombie-> health = 15;
            }
        }
        else if(checkMove(curY,curX-1,heroman) == 9)
        {
            fightT(heroman,troll);
            if(troll->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Troll");
                move(y,x);
                moveGuy(curY, curX-1);
                troll-> health = 50;
            }
        }
        else
        {
            moveGuy(curY,curX);
        }
    }
    //go right
    else if(userPress == 'd')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        move(0,0);
        clrtoeol();
        move(y,x);
        if(checkMove(curY, curX + 1,heroman) == 0)
        {
            moveGuy(curY, curX+1);
        }
        else if(checkMove(curY,curX+1,heroman) == 2)
        {
            hallMove(curY,curX+1);
        }
        else if(checkMove(curY,curX+1,heroman) == 3)
        {
            doorMove(curY,curX+1);
        }
        else if(checkMove(curY,curX+1,heroman) == 4)
        {
            finish(heroman);
        }
        else if(checkMove(curY,curX+1,heroman) == 5)
        {
            fightA(heroman,aquator);
            if(aquator->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed an Aquator");
                move(y,x);
                moveGuy(curY, curX+1);
                aquator-> health = 5;
            }
        }
        else if(checkMove(curY,curX+1,heroman) == 6)
        {
            fightB(heroman,bat);
            if(bat->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Bat");
                move(y,x);
                moveGuy(curY, curX+1);
                bat-> health = 2;
            }
        }
        else if(checkMove(curY,curX+1,heroman) == 7)
        {
            fightS(heroman,snake);
            if(snake->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Snake");
                move(y,x);
                moveGuy(curY, curX+1);
                snake-> health = 5;
            }
        }
        else if(checkMove(curY,curX+1,heroman) == 8)
        {
            fightZ(heroman,zombie);
            if(zombie->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Zombie");
                move(y,x);
                moveGuy(curY, curX+1);
                zombie-> health = 15;
            }
        }
        else if(checkMove(curY,curX+1,heroman) == 9)
        {
            fightT(heroman,troll);
            if(troll->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Troll");
                move(y,x);
                moveGuy(curY, curX+1);
                troll-> health = 50;
            }
        }
        else
        {
            moveGuy(curY,curX);
        }
    }
    //go down
    else if(userPress == 's')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        move(0,0);
        clrtoeol();
        move(y,x);
        if(checkMove(curY+1,curX,heroman) == 0)
        {
            moveGuy(curY+1,curX);
        }
        else if(checkMove(curY+1,curX,heroman) == 2)
        {
            hallMove(curY+1,curX);
        }
        else if(checkMove(curY+1,curX,heroman) == 3)
        {
            doorMove(curY+1,curX);
        }
        else if(checkMove(curY+1,curX,heroman) == 4)
        {
            finish(heroman);
        }
        else if(checkMove(curY+1,curX,heroman) == 5)
        {
            fightA(heroman,aquator);
            if(aquator->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed an Aquator");
                move(y,x);
                moveGuy(curY+1, curX);
                aquator-> health = 5;
            }
        }
        else if(checkMove(curY+1,curX,heroman) == 6)
        {
            fightB(heroman,bat);
            if(bat->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Bat");
                move(y,x);
                moveGuy(curY+1, curX);
                bat-> health = 2;
            }
        }
        else if(checkMove(curY+1,curX,heroman) == 7)
        {
            fightS(heroman,snake);
            if(snake->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Snake");
                move(y,x);
                moveGuy(curY+1, curX);
                snake-> health = 5;
            }
        }
        else if(checkMove(curY+1,curX,heroman) == 8)
        {
            fightZ(heroman,zombie);
            if(zombie->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Zombie");
                move(y,x);
                moveGuy(curY+1, curX);
                zombie-> health = 15;
            }
        }
        else if(checkMove(curY+1,curX,heroman) == 9)
        {
            fightT(heroman,troll);
            if(troll->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Troll");
                move(y,x);
                moveGuy(curY+1, curX);
                troll-> health = 50;
            }
        }
        else
        {
            moveGuy(curY,curX);
        }
    }
    //go up
    else if(userPress == 'w')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        move(0,0);
        clrtoeol();
        move(y,x);
        if(checkMove(curY-1,curX,heroman)==0)
        {
            moveGuy(curY-1,curX);
        }
        else if(checkMove(curY-1,curX,heroman) == 2)
        {
            hallMove(curY-1,curX);
        }
        else if(checkMove(curY-1,curX,heroman) == 3)
        {
            doorMove(curY-1,curX);
        }
        else if(checkMove(curY-1,curX,heroman) == 4)
        {
            finish(heroman);
        }
        else if(checkMove(curY-1,curX,heroman) == 5)
        {
            fightA(heroman,aquator);
            if(aquator->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed an Aquator");
                move(y,x);
                moveGuy(curY-1, curX);
                aquator-> health = 5;
            }
        }
        else if(checkMove(curY-1,curX,heroman) == 6)
        {
            fightB(heroman,bat);
            if(bat->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Bat");
                move(y,x);
                moveGuy(curY-1, curX);
                bat-> health = 2;
            }
        }
        else if(checkMove(curY-1,curX,heroman) == 7)
        {
            fightS(heroman,snake);
            if(snake->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Snake");
                move(y,x);
                moveGuy(curY-1, curX);
                snake-> health = 5;
            }
        }
        else if(checkMove(curY-1,curX,heroman) == 8)
        {
            fightZ(heroman,zombie);
            if(zombie->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Zombie");
                move(y,x);
                moveGuy(curY-1, curX);
                zombie-> health = 15;
            }
        }
        else if(checkMove(curY-1,curX,heroman) == 9)
        {
            fightT(heroman,troll);
            if(troll->health <=0)
            {
                int x = getcurx(stdscr);
                int y = getcury(stdscr);
                mvprintw(0,25,"You killed a Troll");
                move(y,x);
                moveGuy(curY-1, curX);
                troll-> health = 50;
            }
        }
        else
        {
            moveGuy(curY,curX);
        }
    }
    else if(userPress == 'p')
    {
        if(heroman->potion > 0)
        {
            int x = getcurx(stdscr);
            int y = getcury(stdscr);
            heroman->potion = heroman->potion - 1;
            heroman->health = 50;
            move(0,0);
            clrtoeol();
            mvprintw(0,0,"Potion used. Health restored.");
            mvprintw(45,8,"%d",heroman->health);
            move(y,x);
        }
        else
        {
            int x = getcurx(stdscr);
            int y = getcury(stdscr);
            move(0,0);
            clrtoeol();
            mvprintw(0,0,"Not enough potions %d",heroman->potion);
            move(y,x);
        }
    }
    statusBar(heroman);
    heroStatus(heroman);
    int a = getcurx(stdscr);
    int b = getcury(stdscr);
    
    
    patrol(round);
    
    
    move(b,a);
}

void moveGuy(int newY, int newX)
{
    printw(".");
    mvprintw(newY,newX,player);
    move(newY,newX);
}

void hallMove(int newY, int newX)
{
    printw("#");
    mvprintw(newY,newX,player);
    move(newY,newX);
}
void doorMove(int newY, int newX)
{
    printw("+");
    mvprintw(newY, newX, player);
    move(newY, newX);
}
int checkMove(int nextY, int nextX,Hero* heroman)
{
    //statusBar(heroman);
    int x;
    int y;
    char obstacle;
    x = getcurx(stdscr);
    y = getcury(stdscr);
    obstacle = (char)mvinch(nextY,nextX);
    move(y,x);
    
    if(obstacle=='|'||obstacle=='-'||obstacle==' '/*||obstacle=='A'||obstacle=='S'||obstacle=='Z'||obstacle=='T'||obstacle=='B'*/)
    {
        return 1;
    }
    else if(obstacle == '#')
    {
        return 2;
    }
    else if(obstacle == '+')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        mvprintw(0,0,"Opened a door");
        move(y,x);
        return 3;
    }
    else if(obstacle == '*')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        srand(time(NULL));
        heroman->gold = heroman->gold + rand()%50 + 1;
        mvprintw(0,0,"Picked up small gold");
        move(y,x);
        return 0;
    }
    else if(obstacle == '8')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        srand(time(NULL));
        heroman->gold = heroman->gold + rand()%200 + 50;
        mvprintw(0,0,"Picked up big gold");
        move(y,x);
        return 0;
    }
    else if(obstacle == ')')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        if(heroman->inventory<5)
        {
            heroman->attack = heroman->attack + heroman->commonWep;
            heroman->inventory = heroman->inventory + 1;
            heroman->commonCounter = heroman->commonCounter + 1;
            mvprintw(0,0,"Picked up common weapon.");
        }
        else
        {
            mvprintw(0,0,"Inventory full, broke common weapon");
        }
        move(y,x);
        return 0;
    }
    else if(obstacle == '(')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        if(heroman->inventory<5)
        {
            heroman->attack = heroman->attack + heroman->rareWep;
            heroman->inventory = heroman->inventory + 1;
            heroman->rareCounter = heroman-> rareCounter + 1;
            mvprintw(0,0,"Picked up rare weapon.");
        }
        else
        {
            mvprintw(0,0,"Inventory full, broke rare weapon");
        }
        move(y,x);
        return 0;
    }
    else if (obstacle == ']')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        if(heroman-> inventory<5)
        {
            heroman->defence = heroman->defence + heroman->equipment;
            heroman->inventory = heroman->inventory + 1;
            heroman->equipCounter = heroman->equipCounter + 1;
            mvprintw(0,0,"Picked up equipment");
        }
        else
        {
            mvprintw(0,0,"Inventory full.Broke equipment.");
        }
        move(y,x);
        return 0;
    }
    else if (obstacle == '!')
    {
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        heroman->potion = heroman->potion + 1;
        mvprintw(0,0,"Picked up potion.",heroman->potion);
        move(y,x);
        return 0;
    }
    else if (obstacle == '.')
    {
        return 0;
    }
    else if ((obstacle == '>')||(obstacle == '<'))
    {
        return 4;
    }
    else if (obstacle=='A')
    {
        return 5;
    }
    else if (obstacle=='B')
    {
        return 6;
    }
    else if (obstacle=='S')
    {
        return 7;
    }
    else if(obstacle == 'Z')
    {
        return 8;
    }
    else if (obstacle == 'T')
    {
        return 9;
    }
    return 1;
}

void drawMap(int roomnum, room theRooms)
{
    int xX;
    int yY;
    if(roomnum==0)
    {
        yY = 3;
        xX = 2;
    }
    else if(roomnum == 1)
    {
        yY = 3;
        xX = 28;
    }
    else if (roomnum == 2)
    {
        yY = 3;
        xX = 54;
    }
    else if(roomnum == 3)
    {
        yY = 24;
        xX = 2;
    }
    else if(roomnum ==4)
    {
        yY = 24;
        xX = 28;
    }
    else if(roomnum == 5)
    {
        yY = 24;
        xX = 54;
    }
    for(int i = xX; i<(theRooms.x + xX + 1);i++)
    {
        for(int j = yY; j<=(theRooms.y + yY);j++)
        {
            mvaddch(j,i,'.');
        }
    }
    
    mvaddch(theRooms.bGoldy+yY, theRooms.bGoldx+xX,'8');
    mvaddch(theRooms.rWepy + yY, theRooms.rWepx+xX,'(');
    
    for(int w = yY; w<(theRooms.y + yY + 1);w++)
    {
        mvaddch(w,xX,'|');
        mvaddch(w,(theRooms.x + xX + 1),'|');
    }
    for(int v = xX; v<=(theRooms.x + xX + 1);v++)
    {
        mvaddch(yY,v,'-');
    }
    for(int z = xX; z<=(theRooms.x + xX + 1); z++)
    {
        mvaddch((theRooms.y + yY + 1), z, '-');
    }
    
    int check = 0;
    while (theRooms.doorY[check] != 0)
    {
        mvaddch(theRooms.doorY[check],theRooms.doorX[check],'+');
        check++;
    }
    check = 0;
    while (theRooms.sGoldy[check] != 0)
    {
        mvaddch(theRooms.sGoldy[check]+yY, theRooms.sGoldx[check]+xX,'*');
        check++;
    }
    check = 0;
    while (theRooms.stairDY[check] !=0)
    {
        mvaddch(theRooms.stairDY[check]+yY,theRooms.stairDX[check]+xX,'<');
        check++;
    }
    check = 0;
    while(theRooms.stairUY[check] != 0)
    {
        mvaddch(theRooms.stairUY[check]+yY, theRooms.stairUX[check]+xX,'>');
        check ++;
    }
    check = 0;
    while(theRooms.cWepy[check] !=0)
    {
        mvaddch(theRooms.cWepy[check]+yY, theRooms.cWepx[check]+xX,')');
        check ++;
    }
    check = 0;
    char randMon;
    randMon = randMonster();
    
    while(theRooms.wMony[check] !=0)
    {
        mvaddch(theRooms.wMony[check]+yY, theRooms.wMonx[check]+xX,randMon);
        check++;
    }
    check = 0;
    while(theRooms.equipY[check] !=0)
    {
        mvaddch(theRooms.equipY[check]+yY, theRooms.equipX[check]+xX,']');
        check++;
    }
    check =0;
    while(theRooms.sMony[check] != 0)
    {
        mvaddch(theRooms.sMony[check]+yY, theRooms.sMonx[check]+xX,'T');
        check++;
    }
    check = 0;
    while(theRooms.poty[check] != 0)
    {
        mvaddch(theRooms.poty[check]+yY, theRooms.potx[check]+xX,'!');
        check++;
    }
    check = 0;
    
    //drawing the parameter of the hallways
    for(int i = 0; i<80;i++)
    {
        mvaddch(1,i,'#');
        mvaddch(22,i,'#');
        mvaddch(44,i,'#');
    }
    for(int i = 0;i<45;i++)
    {
        mvaddch(i,0,'#');
        mvaddch(i,25,'#');
        mvaddch(i,51,'#');
        mvaddch(i,80,'#');
    }

    getch();

}

char randMonster()
{
    srand(time(NULL));
    int r = rand()%4;
    if(r == 0)
    {
        return 'A';
    }
    else if(r==1)
    {
        return 'B';
    }
    else if (r==2)
    {
        return 'S';
    }
    else if (r==3)
    {
        return 'Z';
    }
    else
        return 'Z';
}

void initHero(Hero* heroman)
{
    heroman->potion = 1;
    heroman->health = 50;
    heroman->attack = 5;
    heroman->inventory = 0;
    heroman->defence = 0;
    heroman->gold = 0;
    heroman->commonCounter = 0;
    heroman-> rareCounter = 0;
}

void statusBar(Hero * heroman)
{
    int x = getcurx(stdscr);
    int y = getcury(stdscr);
    mvprintw(45,1,"Health:%d",heroman->health);
    mvprintw(45,11,"Potions:%d",heroman->potion);
    mvprintw(45,22,"Attack:%d",heroman->attack);
    mvprintw(45,32,"Inventory:%d/5",heroman->inventory);
    move(y,x);
}

void drawHall(room theRooms)
{
    int check = 0;
    while(theRooms.doorY[check] != 0)
    {
        move(theRooms.doorY[check],theRooms.doorX[check]);
        int x = getcurx(stdscr);
        int y = getcury(stdscr);
        char halld;
        char hallu;
        char halle;
        char hallw;
        halld = (char)mvinch(y+1,x);
        hallu = (char)mvinch(y-1,x);
        halle = (char)mvinch(y,x+1);
        hallw = (char)mvinch(y,x-1);
        while(halld== ' ')
        {
           move(y+1,x);
           y = getcury(stdscr);
           mvaddch(y,x,'#');
           halld = (char)mvinch(y+1,x);
        }
        while(hallu == ' ')
        {
            move(y-1,x);
            y = getcury(stdscr);
            mvaddch(y,x,'#');
            hallu= (char)mvinch(y-1,x);
        }
        while(halle == ' ')
        {
            move(y,x+1);
            x = getcurx(stdscr);
            mvaddch(y,x,'#');
            halle = (char)mvinch(y,x+1);
        }
        while(hallw == ' ')
        {
            move(y,x-1);
            x = getcurx(stdscr);
            mvaddch(y,x,'#');
            hallw = (char)mvinch(y,x-1);
        }
        check++;
    }
}

void finish(Hero* heroman)
{
    clear();
    mvprintw(1,1,"Endgame results:");
    mvprintw(7,2,"Gold %d",heroman->gold);
    mvprintw(2,1,"inventory:");
    mvprintw(3,2,"%d common weapon(s) with attack of %d each",heroman->commonCounter,heroman->commonWep);
    mvprintw(4,2,"%d rare weapon(s) with attack of %d", heroman->rareCounter, heroman->rareWep);
    mvprintw(5,2,"%d equipment with %d defence",heroman->equipCounter, heroman->equipment);
    mvprintw(6,1,"Final stats:");
    mvprintw(8,2,"Attack %d", heroman->attack);
    mvprintw(9,2,"Defence %d", heroman->defence);
    mvprintw(10,1,"Press the 'Q' key to quit");
    getch();
    //endwin();
}

void initMonster(Aquator* aquator, Bat* bat, Snake* snake, Zombie* zombie, Troll* troll)
{
    aquator->health = 5;
    aquator->attack = 1;
    aquator->speed = 2;
    bat->health = 2;
    bat->attack = 5;
    bat->speed = 4;
    snake->health = 5;
    snake->attack = 5;
    snake->speed = 4;
    zombie->health = 15;
    zombie->attack = 5;
    zombie->speed = 2;
    troll->health = 50;
    troll->attack = 5;
    troll->speed = 3;
}

void fightA(Hero* heroman, Aquator* aquator)
{
    int heroSpeed;
    int x = getcurx(stdscr);
    int y = getcury(stdscr);
    srand(time(NULL));
    heroSpeed = rand()%10+1;
    if(heroSpeed > aquator->speed)
    {
        mvprintw(0,0,"Hero caused %d attack", heroman->attack);
        move(y,x);
        aquator->health = aquator->health - heroman->attack;
    }
    else
    {
        mvprintw(0,0,"Aquator caused you to lose %d attack",aquator->attack);
        move(y,x);
        heroman->attack = heroman->attack - aquator->attack;
    }
}

void fightB(Hero* heroman, Bat* bat)
{
    int heroSpeed;
    int x = getcurx(stdscr);
    int y = getcury(stdscr);
    srand(time(NULL));
    heroSpeed = rand()%10+1;
    if(heroSpeed > bat->speed)
    {
        mvprintw(0,0,"Hero caused %d attack", heroman->attack);
        move(y,x);
        bat->health = bat->health - heroman->attack;
    }
    else
    {
        mvprintw(0,0,"Bat caused you to lose %d health",bat->attack);
        move(y,x);
        heroman->health = heroman->health - bat->attack;
    }
}

void fightS(Hero* heroman, Snake* snake)
{
    int heroSpeed;
    int x = getcurx(stdscr);
    int y = getcury(stdscr);
    srand(time(NULL));
    heroSpeed = rand()%10+1;
    if(heroSpeed > snake->speed)
    {
        mvprintw(0,0,"Hero caused %d attack", heroman->attack);
        move(y,x);
        snake->health = snake->health - heroman->attack;
    }
    else
    {
        mvprintw(0,0,"Snake caused you to lose %d health",snake->attack);
        move(y,x);
        heroman->health = heroman->health - snake->attack;
    }
}

void fightZ(Hero* heroman, Zombie* zombie)
{
    int heroSpeed;
    int x = getcurx(stdscr);
    int y = getcury(stdscr);
    srand(time(NULL));
    heroSpeed = rand()%10+1;
    if(heroSpeed > zombie->speed)
    {
        mvprintw(0,0,"Hero caused %d attack", heroman->attack);
        move(y,x);
        zombie->health = zombie->health - heroman->attack;
    }
    else
    {
        mvprintw(0,0,"Zombie caused you to lose %d health",zombie->attack);
        move(y,x);
        heroman->health = heroman->health - zombie->attack;
    }
}

void fightT(Hero* heroman, Troll* troll)
{
    int heroSpeed;
    int x = getcurx(stdscr);
    int y = getcury(stdscr);
    srand(time(NULL));
    heroSpeed = rand()%10+1;
    if(heroSpeed > troll->speed)
    {
        mvprintw(0,0,"Hero caused %d attack", heroman->attack);
        move(y,x);
        troll->health = troll->health - heroman->attack;
    }
    else
    {
        mvprintw(0,0,"Troll caused you to lose %d health",troll->attack);
        move(y,x);
        heroman->health = heroman->health - troll->attack;
    }
}

void heroStatus(Hero* heroman)
{
    if(heroman->health<=0)
    {
        finish(heroman);
    }
}

void patrol(int round)
{
    char monster;
    int maxX;
    int maxY;
    int a;
    int b;
    getmaxyx(stdscr,maxY,maxX);
    int batx[10];
    int baty[10];
    int batCount;
    int snakey[10];
    int snakex[10];
    int snakeCount;
    int zomx[10];
    int zomy[10];
    int zombieCount;
    int trollx;
    int trolly;
    batCount = 0;
    snakeCount = 0;
    zombieCount = 0;
    for(int i = 0; i<maxX; i++)
    {
        for(int j=0; j<maxY; j++)
        {
            monster = (char)mvinch(j,i);
            if(monster == 'B')
            {
                move(j,i);
                baty[batCount] = getcury(stdscr);
                batx[batCount] = getcurx(stdscr);
                batCount++;
            }
            else if(monster == 'S')
            {
                move(j,i);
                snakex[snakeCount] = getcurx(stdscr);
                snakey[snakeCount] = getcury(stdscr);
                snakeCount++;
            }
            else if(monster =='Z')
            {
                move(j,i);
                zomx[zombieCount] = getcurx(stdscr);
                zomy[zombieCount] = getcury(stdscr);
                zombieCount++;
            }
            if(monster =='T')
            {
                move(j,i);
                trollx = getcurx(stdscr);
                trolly = getcury(stdscr);
            }
        }
    }
    if(round == 0)
    {
        for(int i =0; i<snakeCount;i++)
        {
            move(snakey[i],snakex[i]);
            char x = (char)mvinch(snakey[i], snakex[i]+1);
            move(snakey[i],snakex[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(snakey[i], snakex[i]+1);
                printw("S");
            }
        }
        for(int i = 0; i<zombieCount; i++)
        {
            move(zomy[i],zomx[i]);
            char x = (char)mvinch(zomy[i]-1, zomx[i]);
            move(zomy[i],zomx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(zomy[i]-1,zomx[i]);
                printw("Z");
            }
        }
        for(int i =0; i<batCount;i++)
        {
            move(baty[i],batx[i]);
            srand(time(NULL));
            a = rand()%3-1;
            b = rand()%3-1;
            char x = (char)mvinch(baty[i]+a, batx[i]+b);
            move(baty[i],batx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(baty[i]+a, batx[i]+b);
                printw("B");
            }
        }
        move(trolly,trollx);
        char x = (char)mvinch(trolly-1, trollx);
        move(trolly,trollx);
       // printw(".");
        if(x=='.')
        {
            printw(".");
            move(trolly-1,trollx);
            printw("T");
        }
        //else
          //  printw("T");
    }
    else if(round == 1)
    {
        for(int i =0; i<snakeCount;i++)
        {
            move(snakey[i],snakex[i]);
            char x = (char)mvinch(snakey[i], snakex[i]+1);
            move(snakey[i],snakex[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(snakey[i], snakex[i]+1);
                printw("S");
            }
        }
        for(int i = 0; i<zombieCount; i++)
        {
            move(zomy[i],zomx[i]);
            char x = (char)mvinch(zomy[i]+1, zomx[i]);
            move(zomy[i],zomx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(zomy[i]+1,zomx[i]);
                printw("Z");
            }
        }
        for(int i =0; i<batCount;i++)
        {
            move(baty[i],batx[i]);
            srand(time(NULL));
            a = rand()%3-1;
            b = rand()%3-1;
            char x = (char)mvinch(baty[i]+a, batx[i]+b);
            move(baty[i],batx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(baty[i]+a, batx[i]+b);
                printw("B");
            }
        }
        move(trolly,trollx);
        char x = (char)mvinch(trolly, trollx+1);
        move(trolly,trollx);
        //printw(".");
        if(x=='.')
        {
            printw(".");
            move(trolly,trollx+1);
            printw("T");
        }
    }
    else if(round == 2)
    {
        for(int i =0; i<snakeCount;i++)
        {
            move(snakey[i],snakex[i]);
            char x = (char)mvinch(snakey[i], snakex[i]-1);
            move(snakey[i],snakex[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(snakey[i], snakex[i]-1);
                printw("S");
            }
        }
        for(int i = 0; i<zombieCount; i++)
        {
            move(zomy[i],zomx[i]);
            char x = (char)mvinch(zomy[i]-1, zomx[i]);
            move(zomy[i],zomx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(zomy[i]-1,zomx[i]);
                printw("Z");
            }
        }
        for(int i =0; i<batCount;i++)
        {
            move(baty[i],batx[i]);
            srand(time(NULL));
            a = rand()%3-1;
            b = rand()%3-1;
            char x = (char)mvinch(baty[i]+a, batx[i]+b);
            move(baty[i],batx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(baty[i]+a, batx[i]+b);
                printw("B");
            }
        }
        move(trolly,trollx);
        char x = (char)mvinch(trolly+1,trollx);
        move(trolly,trollx);
        //printw(".");
        if(x=='.')
        {
            printw(".");
            move(trolly+1,trollx);
            printw("T");
        }
    }
    else if(round == 3)
    {
        for(int i =0; i<snakeCount;i++)
        {
            move(snakey[i],snakex[i]);
            char x = (char)mvinch(snakey[i], snakex[i]-1);
            move(snakey[i],snakex[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(snakey[i], snakex[i]-1);
                printw("S");
            }
        }
        for(int i = 0; i<zombieCount; i++)
        {
            move(zomy[i],zomx[i]);
            char x = (char)mvinch(zomy[i]+1, zomx[i]);
            move(zomy[i],zomx[i]);
            //printw(".");
            if(x=='.')
            {
                printw(".");
                move(zomy[i]+1,zomx[i]);
                printw("Z");
            }
        }
        for(int i =0; i<batCount;i++)
        {
            move(baty[i],batx[i]);
            srand(time(NULL));
            a = rand()%3-1;
            b = rand()%3-1;
            char x = (char)mvinch(baty[i]+a, batx[i]+b);
            move(baty[i],batx[i]);
            printw(".");
            if(x=='.')
            {
                move(baty[i]+a, batx[i]+b);
                printw("B");
            }
        }
        move(trolly,trollx);
        char x = (char)mvinch(trolly, trollx-1);
        move(trolly,trollx);
        printw(".");
        if(x=='.')
        {
            move(trolly,trollx-1);
            printw("T");
        }
    }
}