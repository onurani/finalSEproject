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

//add more here////

//////////////////////
//Struct Definition//
////////////////////


/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

int comparendelete(char myusertext[50], char usertext[50][1000]);

int main(){
	//usertext is a 2d array 
	FILE* infile = NULL;
	const int USER_TEXT_LIMIT = 50;
	int numrow = 1000;
	char usertext[numrow][USER_TEXT_LIMIT];
	infile = fopen("wordList.txt", "r");
	
	for(int i = 0; i < numrow; i++){
		fscanf(infile, "%s", usertext[i]);
	}
	
	for(int j = 0; j < numrow; j++){
		printf("%s\n", usertext[j]);
	}
		
	fclose(infile);
	
	printf("Type one word from the words you see above\n");
	char myusertext[50];
	scanf("%s", myusertext);
	
	int x = comparendelete(myusertext, usertext);
	if(x == 0){
		printf("Match Found\n");
	}
	else{
		printf("No match found\n");
	}
		
	
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////

int comparendelete(char myusertext[50], char usertext[50][1000]){
	
	
	for(int i= 0; i < 1000; i++){
		
		//printf("User entered %s\n", myusertext);
		//printf("Array text is %s\n", usertext[i]);
		
		if(strcmp(myusertext, usertext[i]) == 0){
			printf("User entered %s\n", myusertext);
			printf("Array text is %s\n", usertext[i]);
			printf("Match found in function\n");
			
			
			
			for(int j=i-1; j<1000-1; j++)
			{
				stpcpy(usertext[j], usertext[j + 1]);
			}

			/* Decrement array size by 1 */

			/* Print array after deletion */
			printf("\nElements of array after delete are : ");
			for(int k=0; k<1000; k++)
			{
				printf("%s\n", usertext[k]);
			}
		
		
		
			return 0;
		}
		/*else{
			printf("User entered in else %s\n", myusertext);
			printf("Array text is in else %s\n", usertext[i]);
			printf("No Match found in function\n");
			return 1;
		}*/
	}
}