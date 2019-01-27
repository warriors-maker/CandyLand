#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "board.h"


void buildBoard(nodeRef headRef, nodeRef tailRef){
  int stop = 0;
  nodePtr head = *headRef;
  nodePtr tail = *tailRef;
  //create the file pointer and read in;
  FILE *fp;
  fp = fopen("test.txt","r");
  while(1){
    squarePtr current = createBoardSpace(fp);
    if(current==NULL){
      *headRef = head;
      *tailRef = tail;
      break;
    }
    insertEnd(&head,&tail,current);
  }
  fclose(fp);
}

//create a space each time by each line
squarePtr createBoardSpace(FILE *myFile){
  //delimiters
  const char delimiters[] = " \n";
  char *buf;
  squarePtr space;
  space = malloc(sizeof(square_t));
  //space->color = malloc(sizeof(char)*12);
  //space->special = malloc(sizeof(char)*12);
  //get the first 40 characters
  buf = malloc(sizeof(char)*30);
  fgets(buf,29,myFile);
  //if reach the end;
  if(feof(myFile)){
    return NULL;
  }
  //assign the value in to our squarePtr
  space->color = strtok(buf,delimiters);
  space->special = strtok(NULL,delimiters);
  space-> x = atoi(strtok(NULL,delimiters));
  return space;
}

//
// int charToInt(char *input){
//   int i = 0;
//   while(*(input+i)!='\0'){
//     i++;
//   }
//   i=i-1;
//   int result = 0;
//   int adv = 1;
//   while(i>=0){
//     result = result + (*(input+i)-'0')*adv;
//     i--;
//     adv = adv*10;
//   }
//   return result;
// }


int randomNumber(int upperBound){
  //this is the simple rn generator that generates a random number between 1 and upperBound
  int j;
  j=1+(rand() % upperBound);
  return j;
}

char* intToChar(int x){
  char *input;
  if(x==1){
    input = malloc(4);
    *(input) = 'R';
    *(input+1) = 'E';
    *(input+2) = 'D';
    *(input+3) = '\0';
    return input;
  }
  if(x==2){
    input = malloc(5);
    *(input) = 'B';
    *(input+1) = 'L';
    *(input+2) = 'U';
    *(input+3) = 'E';
    *(input+4) = '\0';
    return input;
  }
  if(x==3){
    input = malloc(7);
    *(input) = 'O';
    *(input+1) = 'R';
    *(input+2) = 'A';
    *(input+3) = 'N';
    *(input+4) = 'G';
    *(input+5) = 'E';
    *(input+6) = '\0';
    return input;
  }
 if(x==4){
    input = malloc(6);
    *(input) = 'G';
    *(input+1) = 'R';
    *(input+2) = 'E';
    *(input+3) = 'E';
    *(input+4) = 'N';
    *(input+5) = '\0';
    return input;
  }
}
void freeBoard(nodePtr head){
  while(head!=NULL){
    nodePtr temp = head;
    head = head->next;
    squarePtr item = (squarePtr) (temp->item);
    //printLine(item->color);
    //printLine(item->special);
    //free(item->color);
    //free(item->special);
    free(item);
    free(temp);
  }
}

void printBoard(void *item){
  squarePtr s= (squarePtr)item;
  char *input1 = (char*) (s->color);
  printLine(input1);
  char *input2 = (char*) (s->special);
  printLine(input2);
  int input3 = (int) (s->x);
  printf("%d",input3);
  printf("\n");
}
