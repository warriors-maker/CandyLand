#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"
//#include "toString.h"
//#include "compare.h"
#include "student.h"

char* getByString();
int getByInt();
char *getStudentInput(int* id);
int menu();

int main(){
  nodePtr head = NULL;
  nodePtr tail = NULL;
  int choice;
  while(1){
    printf("\n");
    printf("\n");
    choice = menu();
    switch(choice){
      case 0:{
        buildStudentList(&head,&tail);
        break;
      }
      case 1:
      {
        forward(printStudent,&head);
        break;
      }
      case 2:
      {
        backward(printStudent,&tail);
        break;
      }
      case 3:
      {
        //deleteNode by Id:
        printf("Input the id you want to delete\n");
        int x = getByInt();
        printf("%d",x);
        deleteNode(compareStudentId,&head,&tail,&x);
        break;
      }
      case 4:
      {
        printf("Input the name you want to delete\n");
        char *name = getByString();
        //printf("I am here");
        deleteNode(compareStudentName,&head,&tail,name);
        break;
      }
      case 5:
      {
        puts("Which ith node you want to print out:");
        int x = getByInt();
        getIthNode(printStudent,head,x);
        break;
      }
      case 6:
      {
        int id = 0;
        char *name = getStudentInput(&id);
        studentPtr s = malloc(sizeof(student_t));
        s->name = name;
        s->id = id;
        insertEnd(&head,&tail,s);
        break;
      }
      case 7:
      {
        printf("Bye!\n");
        exit(0);
      }
    }
  }
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

char *getByString(){
  char *name = malloc(sizeof(char));
  int index=0;
  char a=getchar();
  while(a!='\n'){
    *(name+index) = a;
    index++;
    name = realloc(name,sizeof(char)*(index+1));
    a=getchar();
  }
  *(name+index) = '\0';
  return name;
}

char *getStudentInput(int* id){
  puts("Please input your id and name seperate by space");
  char *number = malloc(sizeof(char));
  int index = 0;
  char a=getchar();
  while(a!=' '){
    *(number+index) = a;
    index++;
    number = realloc(number,sizeof(char)*(index+1));
    a=getchar();
  }
  *(number+index) = '\0';
  *id = atoi(number);

  char *name = malloc(sizeof(char));
  index=0;
  a=getchar();
  while(a!='\n'){
    *(name+index) = a;
    index++;
    name = realloc(name,sizeof(char)*(index+1));
    a=getchar();
  }
  *(name+index) = '\0';
  return name;
}

int menu(){
  int a;
  char carraigeReturn;
  puts("The default main function is for student Node!");
  puts("welcome to Student fun generics");
  puts("please choose from the following choices");
  puts("Make sure that its user duty to keep the generic type consistent!!!");
  puts("0. Read In the default file");
  puts("1. Student Example: print Student nodes with forward direction");
  puts("2. Student Example: print Student nodes with backward direction");
  puts("3. Student Example: Delete a Node by studentID from the DoublyLinkedlist");
  puts("4. Student Example: Delete a Node by studentName from the DoublyLinkedlist");
  puts("5. Student Example: print the ith node you want");
  puts("6. Student Example: Insert a student into the List");
  puts("7. Quit and leave");
  scanf("%d%c", &a, &carraigeReturn);
  return a;
}
