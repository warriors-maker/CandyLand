#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"



typedef struct square{
char * color;    // the color of the space. either red, blue, orange or green;
char * special;  // the special space. There are four values for special spaces: GOBACK, GOFORWARD
                 // WIN and NONE (i.e. nothing special)
int x;           // if you land on a special space, this is how many spaces to move.
                 //If you land on WIN, the game is over and you win.
}square_t;

typedef square_t *squarePtr;

void buildBoard(); //build the overall board;
squarePtr createBoardSpace(); //create a space for each line
//char *readChar(); //read the text file
//int charToInt(char *input); //convert the char number into int number
int randomNumber(int upperBound);
char* intToChar(int x); //the random generated number to a integer
void freeBoard(nodePtr head);
void printBoard(void *item);
