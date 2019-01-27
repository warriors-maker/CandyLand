#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"
//#include "toString.h"


typedef struct player{
  char *name;
  int nameSize;
  nodePtr position;
}player_t;
typedef player_t *playerPtr;

void move(nodeRef posRef, char *input, nodePtr head, nodePtr tail, int* endGame);
char *inputName(int *size);//let user input their name
char *getBack(); //get the char of backward
char *getForward(); //get the char of forward
int onePlayer(nodePtr head,nodePtr tail);//one player Game
void freePlayer(playerPtr player1);
void printSpecial(nodePtr head);
void printName(char *name,int size);
void printLine(char *input);
int compareString(void *item1, void *item2);
int checkWin(char *input);
void twoPlayer(nodeRef gameH, nodeRef gameT,nodePtr head,nodePtr tail);
void printGame(void *player);
void printWinner(void *tailPlayer);
void printPosition(void *item);
int getByInt();
