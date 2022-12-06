//SE 185: Final Project Template//
/////////////////////////
/* TYPING GAME (Option 1)
Team xx (please insert your team number instead of xx)
Team member 1 "Ozair Nurani" | "Percentage of Contribution to The Project: 25%"
Team member 2 "Brendan Kraft" | "Percentage of Contribution to The Project: 25%"
Team member 3 "Chilana A" | "Percentage of Contribution to The Project: 25%"
Team member 4 "Sean F" | "Percentage of Contribution to The Project: 25%"
*/

////////////////////
// header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <curses.h>
#include <ncurses.h>

//global variables
#define WORDLENGTH 15
#define MAXWORDS 1000
char word[50];
int k =2;

/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

void Start_Menu();
void draw(int x, int y, char use);
void drawWord(int x, int y);
int game(int k);
int read_words(char* WL[MAXWORDS], char* file_name);
void trimws(char* str);
void wordadder();

int main()
{

	//Calling the start menu
	Start_Menu();
	while(1){
		//call the core game function
		game(k);
	}
	return 0;
}

//Impementation of the core game fucntion
int game(int k){
	for(int i = 0; i < 2; i++)
	{

			for(int b = 0; b < 2; b++)
			{

			}
	}
	
	
	//Variable declaration
	int totalSeconds=time(NULL);
	char* wordlist[MAXWORDS];
	//Call to read words passing the wordlist file as well as my two-D array
	int wordcount = read_words(wordlist, "wordList.txt");

	//Initialize the screen with ncurses
	initscr();
	int randomNum;
	int randomStartPositionX;
	int i;
    int yMax, xMax;
	int workYLocations[17];
	
	// for loop to increment the y coordinate axis array by 1 for each element
	for(int b = 0; b < 17; b++)
	{
		workYLocations[b] = workYLocations[b] + 1;
	}

	//more variable delcarations for defining the number of rows of the array
	const int USER_TEXT_LIMIT = 50;
	int numrow = 1000;
	char usertext[numrow][USER_TEXT_LIMIT];
    int sizeOfYMax;
    int sizeOfXMax;

    getmaxyx(stdscr, yMax, xMax);

	//New window start for the game
    WINDOW *win = newwin(20, 50, 1, 1);

	//Maximum size of the window calculated
    sizeOfXMax = (xMax /2) - (xMax / 4);
    sizeOfYMax = (yMax / 2) - (yMax / 4);

	//seed random number to time
	srand(time(NULL));
	
    
	//box(win, 0, 0);
	//refresh();
	//for(int c = 0; c <1000; c++){
	srand(time(NULL));
	randomNum = (rand() % numrow) + 1;//getting random word
    srand(time(NULL));
	//calculate the x position randomly to insert the new word
	randomStartPositionX = (rand() % 40) + 1;
    box(win, 0, 0);
	refresh();
	//mvwprintw(win, workYLocations[0], randomStartPositionX, "%s", wordlist[randomNum]);
	wrefresh(win);
		newWord:
		srand(time(NULL));
		//use modulus to calculate random number to use in the two-D array
		randomNum = (rand() % numrow) + 1;
		//calculate the x position randomly against a max base size of 40 units horizontally
		randomStartPositionX = (rand() % 40) + 1;
		wordDisplay:
		//clear out any text from before at the end of the window
		mvprintw(24, 4, "%s", "          ");
		//insert word from two-D array to display on the console
		mvprintw(k, randomStartPositionX, "%s", wordlist[randomNum]);
		wrefresh(win);
		//}
		//mvprintw(3, 3, "%s", "myteacher");
		//}
		 //getch();
		int seconds=time(NULL);
		char myuserinput[100];
		//prepare for user input and recieve the string the user types
		mvprintw(22, 4, "%s", "TypeHere: ");
		 getstr(myuserinput);
		 //printf("I recieved the word %s from the user\n", myuserinput);
		 wrefresh(win);
	
		//do a string compare and check if the user input matches the word displayed
		 if(strcmp(myuserinput, wordlist[randomNum])==0){
			//printf("The word matched this time\n");
			//erase the word since the user typed it correctly 
			mvprintw(k, randomStartPositionX, "%s", "            ");
			//keep tab on time to watch how long the player is taking to type
			k+=(int)(time(NULL)-seconds);
			//increment against time while playing the game to keep score of time in seconds
			for(i = 1; i < (int)(time(NULL) - seconds); i++){
				//display one more word to the screen at a random x position and increment y position by 1
				mvprintw(k - i, (rand() % 40) + 1, "%s", wordlist[(rand() % numrow) + 1]);
			}
			//y axis coordinate has reached bottom of the screen, thus we need to inform the user of end game time
			if(k>=20){
				endwin();
				printf("YOUR TIME WAS: %d",time(NULL)-totalSeconds);
				exit(0);
			}
			//clear screen for extra characters from previous runs
			mvprintw(22, 14, "%s", "                        ");
			wrefresh(win);
			goto newWord;
		 }
		 //the word the user types did not match possibly because of a typo or mistake
		 else{
			mvprintw(24, 4, "%s", "INCORRECT");
			//clear the word that was typed incorrectly and move it to another location still visible on the window
			mvprintw(k, randomStartPositionX, "%s", "            ");
			k+=(int)(time(NULL)-seconds);
			//the user reached the limit of time
			if(k>=20){
				//end the game and inform the player of the total time they took
				endwin();
				printf("YOUR TIME WAS: %d",time(NULL)-totalSeconds);
				exit(0);
			}
			//clear old displayed words
			mvprintw(22, 14, "%s", "                        ");
			wrefresh(win);
			goto wordDisplay;
		 }
		 
		 
	wclear(win);
	//delwin(win);
    //endwin();
	return 0;
}
//implementation of start menu
void Start_Menu()
{
	char answer;
	printf("Hello, this is a typing game. you will need to type the words as they appear\n");
	printf("Would you like to play the game or would you like to add words or would you like to exit?(y/a/n)\n");
	scanf(" %c", &answer);
	//if else for user input to play game or add words to the file or exit
	if(answer == 'y' || answer == 'Y')
	{
		printf("Good luck!\n");
	}
	else if(answer == 'a' || answer == 'A'){
		wordadder();
	}
	else
	{
		printf("exiting game");
		exit(0);
	}
}
//implementation for draw
void draw(int x, int y, char use)
{
    x = abs(x);
    y = abs(y);
    mvaddch(y, x, use);
    refresh();
}
//implementation for drawWord
void drawWord(int x, int y)
{
    x = abs(x);
    y = abs(y);
    mvaddstr(y, x, "test");
    refresh();
}
//implementation for trimws
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	//trim the end of word \0 which is not needed in this game
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}

//implementation of wordadder to add words to the text file if the user chose this option
void wordadder(){
	
	//create a file pointer and open the file in append mode (write at the tail of the file)
	FILE *fpadder = fopen("wordList.txt","a");
	
	//ask user for the word and recieve the response 
	char myuseradder[100];
	printf("Give me a word to add to the file\n");
	scanf("%s", myuseradder);
	
	//append the word the user gave us to the bottom of the wordlist text file
	fprintf(fpadder, "\n%s", myuseradder);
	//make sure to close the file
	fclose(fpadder);
	return;
}

//read words function to read from the text file to write to my two-D array
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	//create file pointer and open the file in read only mode
	FILE* fp = fopen(file_name, "r");
	//keep reading from the file until the end of the file, one line at a time
	while (!feof(fp)) {
		//get one line at a time
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			//trim termination (extra) characters at the end of each word
			trimws(line);
			//allocate memory for the two-D array iteratively
			WL[numread] = (char *)malloc(strlen(line) + 1);
			//copy each word from the file to the two-D array
			strcpy(WL[numread], line);
			numread++;
		}
	}
	//make sure to close the file
	fclose(fp);
	return numread;
}

