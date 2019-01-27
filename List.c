#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"


void insertEnd(nodeRef headRef,nodeRef tailRef, void *item){
  //CREATE THE INSERTING Node
  nodePtr Node;
  Node = malloc(sizeof(node_t));
  Node->item = item;
  Node->prev = NULL;
  Node->next = NULL;
  //Empty
  if(*headRef == NULL){
    *headRef = Node;
    *tailRef = *headRef;
    return;
  }
  //When there is only one node
  if( (*tailRef)-> prev == NULL){
    (*headRef) -> next = Node;
    Node-> prev = *headRef;
    *tailRef = Node;
    return;
  }
  //other cases
  (*tailRef)->next = Node;
  Node -> prev = *tailRef;
  *tailRef = Node;
}

void forward(void (*print)(void *a),nodeRef headRef){
  if( (*headRef)==NULL){
    printf("Nothing is in the List\n");
    return;
  }
  printf("Here are the traverseForward items:\n");
  nodePtr moveNode = *headRef;
  while (moveNode!=NULL){
    print(moveNode->item);
    moveNode = moveNode->next;
  }
}
void backward(void (*print)(void *a),nodeRef tailRef){
  if( (*tailRef)==NULL){
    printf("Nothing is in the List\n");
    return;
  }
  printf("Here are the traverseBackward items: \n");
  nodePtr moveNode = *tailRef;
  while(moveNode!=NULL){
    print(moveNode->item);
    moveNode = moveNode->prev;
  }
}

void getIthNode(void (*print)(void *a),nodePtr headPtr, int target){
  nodePtr move = headPtr;
  if(move==NULL){
    puts("The List is Empty!!");
    return;
  }
  while(target>1){
    move = move->next;
    if(move==NULL){
      puts("List out of bound!!!");
      return;
    }
    target--;
  }
  print(move->item);
}

 void deleteNode(int (*compare)(void * A, void * B),nodeRef headRef,nodeRef tailRef, void *item){
   if( (*headRef == NULL)) return;
   //If oneNode
   if( (*headRef)->next==NULL){
     if(compare((*headRef)->item,item)!=0){
       puts("The one you want to delete is not in the List.");
       return;
     }
     *headRef = NULL;
     *tailRef = NULL;
     return;
   }
   //other cases
   nodePtr move = *headRef;
   nodePtr prev = *headRef;
   //if head is deleted
   //printf("insdie the loop");
   if(compare((*headRef)->item,item)==0){
     //printf("I am head");
     *headRef = (*headRef)->next;
     (*headRef)->prev = NULL;
      return;
   }
   //if tail is deleted
   if(compare((*tailRef)->item,item)==0){
     *tailRef = (*tailRef)->prev;
     (*tailRef)->next = NULL;
     return;
   }
   while(move!=NULL){
     if(compare(move->item,item)==0){
       prev->next = (prev->next)->next;
       nodePtr temp = prev->next;
       temp->prev = prev;
       //printf("Hi\n");
       return;
     }
     prev = move;
     move = move->next;
   }
   printf("Your target item is not found so no change in the linkedList\n");
 }
