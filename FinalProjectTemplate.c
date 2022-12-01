//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Ozair Nurani" | "Percentage of Contribution to The Project"
Team member 2 "Brendan Kraft" | "Percentage of Contribution to The Project"
Team member 3 "Chilana A" | "Percentage of Contribution to The Project"
Team member 4 "Sean F" | "Percentage of Contribution to The Project"
*/

////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <curses.h>
#include <ncurses.h>


//global
char word[50];

//add more here////

//////////////////////
//Struct Definition//
////////////////////

void draw(int x, int y, char use);
void drawWord(int x, int y);
/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

int main()
{
	initscr();
	int randomNum;
	int randomStartPositionX;
	int i;
    int yMax, xMax;


	const int USER_TEXT_LIMIT = 50;
	int numrow = 1000;
	char usertext[numrow][USER_TEXT_LIMIT];



	FILE* infile = NULL;
	infile = fopen("wordList.txt", "r");


    int sizeOfYMax;
    int sizeOfXMax;


    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(20, 50, 1, 1);

    sizeOfXMax = (xMax /2) - (xMax / 4);
    sizeOfYMax = (yMax / 2) - (yMax / 4);

	srand(time(NULL));
	randomNum = (rand() % numrow) + 1;//getting random word

    box(win, 0, 0);

    //mvwprintw(win,0, 2, "Test");

	mvwprintw(win, 0, 5, "%d", randomNum);
    
	for(i = 0; i < 1000; i++){
		//fscanf(infile, "%s", word[50]);
		if(i == randomNum)
		{
			mvwprintw(win, 0, randomNum, "testv2");
		}
	}
    
    wgetch(win);

		
	fclose(infile);
    endwin();
	return 0;
}
void draw(int x, int y, char use)
{
    x = abs(x);
    y = abs(y);
    mvaddch(y, x, use);
    refresh();
}
void drawWord(int x, int y)
{
    x = abs(x);
    y = abs(y);
    mvaddstr(y, x, "test");
    refresh();
}
///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////
