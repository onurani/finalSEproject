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

//add more here////

//////////////////////
//Struct Definition//
////////////////////

void draw(int x, int y, char use);
void drawWord(int x, int y, char word[50]);
void drawMaze();
/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

int main()
{
	int randomNum;
	int randomStartPositionX;
	int i;


	initscr();

	//usertext is a 2d array 
	FILE* infile = NULL;
	const int USER_TEXT_LIMIT = 50;
	int numrow = 1000;
	char usertext[numrow][USER_TEXT_LIMIT];
	infile = fopen("wordList.txt", "r");


	drawMaze();

	
	srand(time(NULL));
	randomNum = (rand() % 1000) + 1;//getting random word

	for(i = 0; i < numrow; i++){
		fscanf(infile, "%s", usertext[i]);
		if(i == randomNum)
		{
			drawWord(5, 10, usertext[i]);
    		mvaddch(5, 10, usertext[i]);
			break;
		}
	}


		
	fclose(infile);
    refresh();
	return 0;
}

void drawMaze()
{
        for(int i = 0; i < 23; i++)
        {
            draw(0, i, '|');
        }
        //drawing right wall
        for(int i = 0; i < 23; i++)
        {
            draw(80 ,i,'|');
        }
        //drawing ceiling
        for(int i = 0; i < 80; i++)
        {
            draw(i+1, 24, '-');
        }
        for(int i = 0; i < 80; i++)
        {
            draw(i, 24, '-');
        }
}
void draw(int x, int y, char use)
{
    x = abs(x);
    y = abs(y);
    mvaddch(y, x, use);
    refresh();
}
void drawWord(int x, int y, char word[50])
{
    x = abs(x);
    y = abs(y);
    mvaddch(y, x, word[50]);
    refresh();
}
///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////
