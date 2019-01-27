#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "board.h"



int main(){
    srand((unsigned)time(NULL));
    nodePtr head = NULL;
    nodePtr tail = NULL;

    //Building the boad;
    //always remenber to pass in the address if you want to change the global value;
    buildBoard(&head,&tail);
    forward(printBoard,&head);
    backward(printBoard,&tail);
    printf("\n");

    int time = 0;
    int sum = 0;
    while(time<5){
      int count = 0;
      count = onePlayer(head,tail);
      printf("It takes %d times to win \n",count);
      printf("\n");

      sum+=count;
      time++;
    }
    //printSpecial(head);
    freeBoard(head);
    double result = sum/5;
    printf("The average is %lf\n",result);
}
