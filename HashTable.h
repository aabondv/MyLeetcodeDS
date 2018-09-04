#ifndef HASHTABLE_H
#define HASHTABLE_H

//#define PRIME_TBLSIZ 1699
#include <stdio.h>
#include "LinkedList.h"

struct HashTable{
    int length;
    LinkedList *list;
};
typedef struct HashTable *HashTable;


void hashTableInit();

void hashTableInsert(HashTable table, int data);

void hashTableRemove(HashTable table, int data);

int hashTableLookup(HashTable table, int data);

#endif // HASHTABLE_H
