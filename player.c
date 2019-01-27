#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"
#include <string.h>


//If your .h file contains another .h file
//you do not need to include that .h file again in your .c file
char *inputName(int *size){
  char *name = malloc(sizeof(char));
  int i = 0;
  char a=getchar();
  while(a!='\n'){
    *(name+i)=a;
    i++;
    name = realloc(name,i+1);
    a=getchar();
  }
  *(size) = i;
  return name;
}

void printName(char *name,int size){
  int index =0;
  while(index<size){
    printf("%c",*(name+index));
    index++;
  }
}

void move(nodeRef posRef, char *input, nodePtr head, nodePtr tail, int* endGame){
  nodePtr move;
  //this nodePter helps us to go back to original space
  //when we try to win the game without the same color;
  nodePtr prev;
  prev = *posRef;
  //initial;
  if(*posRef == NULL){
    move = head;
  }
  else{
    move = *posRef;
    move = move->next;
  }
  //cast it into the squarePtr since itemField in nodePtr are *void
  // printf("Current color:");
  // printLine(input);
  // printf("\n");

  squarePtr item = (squarePtr) (move->item);
  //advance;
  //printf("Pass through\n:");
  while(compareString(item->color,input) != 0){
    // printLine(item->color);
    // printLine(item->special);
    // printf("\n");
    //End the game
    if(checkWin(((squarePtr)(move->item))->special)==1){
      //if the color we roll does not match the end node;
      if(compareString(item->color,input)!=0){
        //reset our moveNode back to prevNode;
        //since the color does not match;
        printf("Does not match win color, stay!\n");
        move = prev;
        break;
      }
      *(endGame) = 1;
      break;
    }
    move = move->next;
    item = (squarePtr) (move->item);
  }

  //check special case
  //1.MoveForward
  while(compareString(getForward(),((squarePtr)(move->item))->special) == 0
  || compareString(getBack(),((squarePtr)(move->item))->special)==0){
    if(compareString(getForward(),((squarePtr)(move->item))->special) == 0){
      int step = ((squarePtr)(move->item))->x;
      printf("Get Advanced by %d steps",step);
      printf("\n");
      //printf("MoveForward%d\n",step);
      while(step!=0){
        move = move->next;
        step--;
        if(checkWin(((squarePtr)(move->item))->special)==1){
          //since in this case we just advance; no need to check the color
          *(endGame) = 1;
        }
      }
    }
  //
  // }
  //moveBackward
    if(compareString(getBack(),((squarePtr)(move->item))->special)== 0){
      int step = ((squarePtr)(move->item))->x;
      printf("MoveBack %d steps",step);
      printf("\n");
      while(step!=0){
        move = move->prev;
        step--;
      }
    }
  }
  //
  // }
  //printf("\n");
  *posRef = move;
}

char *getBack(){
  char *input = malloc(7);
  *input = 'G';
  *(input+1) = 'O';
  *(input+2) = 'B';
  *(input+3) = 'A';
  *(input+4) = 'C';
  *(input+5) = 'K';
  *(input+6) = '\0';
  return input;
}

char *getForward(){
  char *input = malloc(10);
  *input = 'G';
  *(input+1) = 'O';
  *(input+2) = 'F';
  *(input+3) = 'O';
  *(input+4) = 'R';
  *(input+5) = 'W';
  *(input+6) = 'A';
  *(input+7) = 'R';
  *(input+8) = 'D';
  *(input+9) = '\0';
  return input;
}

int onePlayer(nodePtr head,nodePtr tail){
  //the Turn for the player to play the game now
  int x;
  char *color;
  int endGame = 0;
  playerPtr player1 = malloc(sizeof(player_t));
  //player1->name = inputName();
  player1->position = NULL;
  int count = 0;
  while(1){
    x = randomNumber(4);
    //printf("RandomNumber is %d\n",x);
    color = intToChar(x);
    printf("Here is the color current player rolled:");
    printLine(color);
    printf("\n");
    move(&(player1->position),color,head,tail,&endGame);
    count++;
    if(endGame==1){
      player1->position = NULL;
      freePlayer(player1);
      break;
    }
  }
  return count;
}

void twoPlayer(nodeRef gameH, nodeRef gameT,nodePtr head,nodePtr tail){
  playerPtr player1 = malloc(sizeof(player_t));
  player1->position = NULL;
  int size1=0;
  printf("please input your name player1:\n");
  char *name1 = inputName(&size1);
  player1->name = name1;
  player1->nameSize = size1;

  printf("please input your name player2:\n");
  playerPtr player2 = malloc(sizeof(player_t));
  player2->position = NULL;
  int size2=0;
  char *name2 = inputName(&size2);
  player2->name = name2;
  player2->nameSize = size2;

  int endGame1 = 0;
  int endGame2 = 0;
  //hold the games

  nodePtr gameHead=NULL;
  nodePtr gameTail=NULL;

  while(1){
    printName(player1->name,player1->nameSize);
    printf(" moves");
    int move1 = randomNumber(4);
    char *color1 = intToChar(move1);
    printf(" Color rolled:");
    printLine(color1);
    printf(" ");

    move(&(player1->position),color1,head,tail,&endGame1);
    playerPtr p1 = malloc(sizeof(player_t));
    p1->name = player1->name;
    p1->nameSize = player1->nameSize;
    p1->position = player1->position;
    insertEnd(&gameHead,&gameTail,p1);

    if(endGame1 == 1){
      printf("\n");
      printName(player1->name,player1->nameSize);
      printf(" wins\n");
      *gameH = gameHead;
      *gameT = gameTail;
      free(player1);
      free(player2);
      break;
    }
    printf("\n");
    printName(player2->name,player2->nameSize);
    printf(" moves");
    int move2 = randomNumber(4);
    char *color2 = intToChar(move2);
    printf(" Color rolled:");
    printLine(color2);
    printf(" ");
    move(&(player2->position),color2,head,tail,&endGame2);
    playerPtr p2 = malloc(sizeof(player_t));
    p2->name = player2->name;
    p2->nameSize = player2->nameSize;
    p2->position = player2->position;
    insertEnd(&gameHead,&gameTail,p2);

    if(endGame2 == 1){
      printf("\n");
      printName(player2->name,player2->nameSize);
      printf(" wins\n");
      *gameH = gameHead;
      *gameT = gameTail;
      free(player1);
      free(player2);
      break;
    }
    printf("\n");
  }
}

void printSpecial(nodePtr head){
  while(head!=NULL){
    nodePtr move=head;
    head= head->next;
    squarePtr item = (squarePtr)(move->item);
    printLine(item->color);
    printLine(item->special);

  }
}
void printLine(char *input){
  int i = 0;
  while(*(input+i)!='\0'){
    printf("%c",*(input+i));
    i++;
  }
  printf(" ");
}

int compareString(void *item1, void *item2){
  char *x = (char*)(item1);
  char *y = (char*)(item2);
  return strcmp(item1,item2);
}

int checkWin(char *input){
  if(*input =='W' && *(input+1)=='I' && *(input+2) == 'N' && *(input+3)=='\0'){
    return 1;
  }
}

void freePlayer(playerPtr player){
  free(player);
}
  void printGame(void *player){
    playerPtr p = (playerPtr)player;
    printName(p->name,p->nameSize);
    printf(" ");
    printPosition((p->position)->item);
  }

  void printWinner(void *n){
    playerPtr p = (playerPtr)(n);
    printName(p->name,p->nameSize);
  }

  void printPosition(void *item){
    squarePtr s= (squarePtr)item;
    char *input1 = (char*) (s->color);
    printLine(input1);
    printf(" ");
    printf("\n");
  }

  int getByInt(){
    char *number = malloc(sizeof(char));
    int index = 0;
    char a=getchar();
    while(a!='\n'){
      *(number+index) = a;
      index++;
      number = realloc(number,sizeof(char)*(index+1));
      a=getchar();
    }
    *(number+index) = '\0';
    int id = atoi(number);
    return id;
  }
