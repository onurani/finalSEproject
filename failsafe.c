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
int k =2;

//add more here////

//////////////////////
//Struct Definition//
////////////////////

void Start_Menu();
void draw(int x, int y, char use);
void drawWord(int x, int y);
int game(int k);
/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////


int read_words(char* WL[MAXWORDS], char* file_name);



void trimws(char* str);


int main()
{

	Start_Menu();
	while(1){
		game(k);
	}
	/* seconds
	if goes up then call function a-1
	else 
	call function of a
	*/
	
}


int game(int k){
	for(int i = 0; i < 2; i++)
	{

			for(int b = 0; b < 2; b++)
			{

			}
	}
	
	
	
	int totalSeconds=time(NULL);
	char* wordlist[MAXWORDS];
	int wordcount = read_words(wordlist, "wordList.txt");

	initscr();
	int randomNum;
	int randomStartPositionX;
	int i;
    int yMax, xMax;
	int workYLocations[17];
	
	for(int b = 0; b < 17; b++)
	{
		workYLocations[b] = workYLocations[b] + 1;
	}


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
	
    
	//box(win, 0, 0);
	//refresh();
	//for(int c = 0; c <1000; c++){
	srand(time(NULL));
	randomNum = (rand() % numrow) + 1;//getting random word
    srand(time(NULL));
	randomStartPositionX = (rand() % 40) + 1;
    box(win, 0, 0);
	refresh();
	//mvwprintw(win, workYLocations[0], randomStartPositionX, "%s", wordlist[randomNum]);
	wrefresh(win);
		newWord:
		srand(time(NULL));
		randomNum = (rand() % numrow) + 1;
		randomStartPositionX = (rand() % 40) + 1;
		wordDisplay:
		mvprintw(24, 4, "%s", "          ");
		mvprintw(k, randomStartPositionX, "%s", wordlist[randomNum]);
		wrefresh(win);
		//}
		//mvprintw(3, 3, "%s", "myteacher");
		//}
		 //getch();
		int seconds=time(NULL);
		char myuserinput[100];
		mvprintw(22, 4, "%s", "TypeHere: ");
		 getstr(myuserinput);
		 //printf("I recieved the word %s from the user\n", myuserinput);
		 wrefresh(win);

		 if(strcmp(myuserinput, wordlist[randomNum])==0){
			//printf("The word matched this time\n");
			mvprintw(k, randomStartPositionX, "%s", "            ");
			//clrtoeol();
			k+=(int)(time(NULL)-seconds);
			for(i = 1; i < (int)(time(NULL) - seconds); i++){
				mvprintw(k - i, (rand() % 40) + 1, "%s", wordlist[(rand() % numrow) + 1]);
			}
			if(k>=20){
				endwin();
				printf("YOUR TIME WAS: %d",time(NULL)-totalSeconds);
				exit(0);
			}
			mvprintw(22, 14, "%s", "                        ");
			wrefresh(win);
			goto newWord;
		 }
		 else{
			mvprintw(24, 4, "%s", "INCORRECT");
			mvprintw(k, randomStartPositionX, "%s", "            ");
			k+=(int)(time(NULL)-seconds);
			if(k>=20){
				endwin();
				printf("YOUR TIME WAS: %d",time(NULL)-totalSeconds);
				exit(0);
			}
			mvprintw(22, 14, "%s", "                        ");
			wrefresh(win);
			goto wordDisplay;
		 }
		 
		 
	wclear(win);
	//delwin(win); //commenting cause it closes the window too soon
    //endwin(); //same reason as above
	return 0;
}
void Start_Menu()
{
	char answer;
	printf("Hello, this is a typing game. you will need to type the words as they appear\n");
	printf("Would you like to play the game?(y/n)\n");
	scanf(" %c", &answer);
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
