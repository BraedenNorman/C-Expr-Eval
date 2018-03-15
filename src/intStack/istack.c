/*
 *  Title: Integer Stack ADT
 *  Author:  Braeden Norman
 *  Date:    2018/03/08
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "istack.h"

Node2_t* node2Create(int value) {
    Node2_t* node = malloc(sizeof(Node2_t));
    node->data = value;
    node->next = NULL;
    return node;
}


IntStack_t istackCreate( ){
   IntStack_t stack = {NULL};
   return stack;
}

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack ){
   while (stack->head != NULL) {
      Node2_t* cur = stack->head;
      stack->head = stack->head->next;
      free(cur);
   }
}	 

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  ){
   Node2_t* cur = stack.head;
   printf("\nStack:  ");
   while (cur != NULL) {
       printf("[%d]%s", cur->data, cur->next ? "-->" : "--|");
       cur = cur->next;
   }
   printf("\n\n");
}	

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty(const IntStack_t stack ){
	return stack.head ==  NULL;
}

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack ){
	assert(!istackIsEmpty(stack));
	return (stack.head->data);
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack ){
	assert(!istackIsEmpty(*stack));
	Node2_t* node = stack->head;
    stack->head = stack->head->next;
    int value = node->data;
    free(node);
    return value;
}

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item){
	Node2_t* newNode = node2Create(item);
    if (istackIsEmpty(*stack)) {
        stack->head = newNode;
    }
    else {
        newNode->next = stack->head;
        stack->head = newNode;
    }
}
