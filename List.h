#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
   void * item;
   struct node * next;
   struct node * prev;
}node_t;

typedef node_t *nodePtr;
typedef nodePtr *nodeRef;

void insertEnd(nodeRef headRef,nodeRef tailRef,void *item);
void forward(void (*print)(void *a),nodeRef headRef);
void backward(void (*print)(void *a),nodeRef tailRef);
void deleteNode(int (*compare)(void * A, void * B),nodeRef headRef, nodeRef tailRef,void * item);
void getIthNode(void (*print)(void *a),nodePtr headPtr, int target);
