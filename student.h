#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct student {
   int id;
   char *name;
}student_t;

typedef student_t *studentPtr;

studentPtr createStudent(FILE *myFile){
  //delimiters
  const char delimiters[] = " \n";
  char *buf;
  studentPtr s;
  s = malloc(sizeof(student_t));
  s->name = malloc(sizeof(char)*15);
  //get the first 40 characters
  buf = malloc(sizeof(char)*30);
  fgets(buf,25,myFile);
  //if reach the end;
  if(feof(myFile)){
    return NULL;
  }
  //assign the value in to our squarePtr
  s->id = atoi(strtok(buf,delimiters));
  s->name = strtok(NULL,delimiters);
  return s;
}
void buildStudentList(nodeRef headRef, nodeRef tailRef){
  nodePtr head = *headRef;
  nodePtr tail = *tailRef;
  //create the file pointer and read in;
  FILE *fp;
  fp = fopen("student.txt","r");
  while(1){
    studentPtr current = createStudent(fp);
    if(current==NULL){
      break;
    }
    insertEnd(&head,&tail,current);
  }
  *headRef = head;
  *tailRef = tail;
  fclose(fp);
}

void printStudent(void *item){
  student_t *s = (student_t*)item;
  int x = s->id;
  char *input1 = s->name;
  printf("The student id is %d and the student name is %s\n",x,input1);
}

int compareStudentId(void *item1,void *item2){
  studentPtr s1 = (studentPtr)item1;
  int* num = (int*)item2;
  int x1 = s1->id;
  return x1 - (*num);
}

int compareStudentName(void *item1,void *item2){
  studentPtr s1 = (studentPtr)item1;
  char *x = (char*)item2;
  char *y = s1->name;
  return strcmp(x,y);
}
