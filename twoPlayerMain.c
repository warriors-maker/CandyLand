#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "board.h"

int menu(){
  int a;
  char carraigeReturn;
  puts("This is a two Player game and we use a generic doubly linkedlist to hold the players!");
  puts("Here are the choices you can have!");
  puts("HAVE FUN!");
  puts("0. Start the game");
  puts("1. Traverse the whole game two player's position");
  puts("2. print the ith move of the game");
  puts("3. print the winner");
  puts("4. print the board forward");
  puts("5. print the board backward");
  puts("6. Rematch");
  puts("7. Quit!");
  scanf("%d%c", &a, &carraigeReturn);
  return a;
}

int main(){
        srand((unsigned)time(NULL));
        nodePtr head = NULL;
        nodePtr tail = NULL;
        nodePtr gameHead = NULL;
        nodePtr gameTail = NULL;
        int choice;
        while(1){
          printf("\n");
          printf("\n");
          choice = menu();
          switch(choice){
            case 0:
            {
              printf("\n");
              buildBoard(&head,&tail);
              twoPlayer(&gameHead,&gameTail,head,tail);
              break;
            }
            case 1:
            {
              forward(printGame,&gameHead);
              break;
            }
            case 2:
            {
              puts("Which ith node you want to print out:");
              int x = getByInt();
              getIthNode(printGame,gameHead,x);
              break;
            }
            case 3:
            {
              printf("The winner is: ");
              printWinner(gameTail->item);
              break;
            }
            case 4:
            {
              forward(printBoard,&head);
              break;
            }
            case 5:
            {
              backward(printBoard,&tail);
              break;
            }
            case 6:
            {
              head = NULL;
              tail = NULL;
              gameHead = NULL;
              gameTail = NULL;
              buildBoard(&head,&tail);
              twoPlayer(&gameHead,&gameTail,head,tail);
              break;
            }
            case 7:
            {
              puts("Bye!!!");
              exit(0);
            }
          }
        }
      }
