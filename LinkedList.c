#include "LinkedList.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAD_VAL 0x12345678

void linkedListCheckIndex(LinkedList list, int index)
{
    checkNullPointer(list);
    if(index < 0 || index > linkedListSize(list))
    {
        fprintf(stderr, "input %d, must be between 0 and %d", index, linkedListSize(list));
        exit(0);
    }

}
void linkedListInit(LinkedList *list)
{
    checkNullPointer(list);
    *list = malloc(sizeof(struct ListNode));
    (*list)->val = INIT_HEAD_VAL;
    (*list)->next = NULL;
}
void linkedListInsert(LinkedList list, int index, int val)
{
    linkedListCheckIndex(list, index);
    if(index == 0 && linkedListSize(list) == 1 && list->val == INIT_HEAD_VAL)
    {
        list->val = val;
        return;
    }
    LinkedList *node = malloc(sizeof(struct ListNode));
    node->val = val;


}
void linkedListAdd(LinkedList list, int val)
{

}
void linkedListRemove(LinkedList list, int index)
{

}
int linkedListSize(LinkedList list)
{
    checkNullPointer(list);
    int size = 0;
    while(list->next)
    {
        size++;
        list = list->next;
    }
    return size + 1;
}
int linkedListGet(int index)
{

}
