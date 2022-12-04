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

#define WORDLENGTH 15
#define MAXWORDS 1000

//global
char word[50];

//add more here////

//////////////////////
//Struct Definition//
////////////////////
void Start_Menu();
void draw(int x, int y, char use);
void drawWord(int x, int y);
/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////


int read_words(char* WL[MAXWORDS], char* file_name);


void trimws(char* str);


int main()
{

	//Start_Menu();

	char* wordlist[MAXWORDS];
	int wordcount = read_words(wordlist, "wordList.txt");


	initscr();
	int randomNum;
	int randomStartPositionX;
	int i;
    int yMax, xMax;


	const int USER_TEXT_LIMIT = 50;
	int numrow = 1000;
	char usertext[numrow][USER_TEXT_LIMIT];


    int sizeOfYMax;
    int sizeOfXMax;


    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(20, 50, 1, 1);

    sizeOfXMax = (xMax /2) - (xMax / 4);
    sizeOfYMax = (yMax / 2) - (yMax / 4);

	srand(time(NULL));
	randomNum = (rand() % numrow) + 1;//getting random word
    srand(time(NULL));
    randomStartPositionX = (rand() % 40) + 1;

    box(win, 0, 0);
	refresh();

	mvwprintw(win, 1, randomStartPositionX, "%s", wordlist[randomNum]);
	wrefresh(win);
    
    getch();

		
	delwin(win);
    endwin();
	return 0;
}
void Start_Menu()
{
	char answer;
	printf("Hello, this is a typing game. you will need to type the words as they appear\n");
	printf("Would you like to play the game?(y/n)\n");
	scanf("%c", answer);
	if(answer == 'y' || answer == 'Y')
	{
		printf("Good luck!\n");
	}
	else
	{
		printf("exiting game");
		exit(0);
	}
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

void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}

int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
/*void clock(){
    int true=1;
    time_t seconds;
    seconds = time(NULL);
    while(true==1){
        time_t currentSeconds;
        currentSeconds = time(NULL);
        if(currentSeconds!= seconds){
            //update y
            break;
        }else if(currentSeconds<seconds){
            break;
        }
    }
}*/