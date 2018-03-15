/**
 *  Generic Queue ADT : public interface
 *    Dependency: LinkedList with data type defined by gentype.h
 *
 *  Author:  Joseph Fall
 *  Date:    Mar. 1, 2018
 */

#include "linkedlist.h"

/*********************
 *  PUBLIC INTERFACE
 *********************/
typedef LinkedList_t Queue_t;

Queue_t qCreate();

void qDestroy(Queue_t* q);

void qPrint(const Queue_t q);

bool qIsEmpty(const Queue_t q);

void qClear(Queue_t* q);

int qLength(const Queue_t q);

void qEnqueue(Queue_t* q, ItemType value);

ItemType qFront(const Queue_t q);

ItemType qDequeue(Queue_t* q);

