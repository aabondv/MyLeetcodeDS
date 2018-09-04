#include "LinkedList.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAD_VAL 0x12345678

void linkedListCheckAddIndex(LinkedList list, int index)
{
    checkNullPointer(list);
    if(index < 0 || index > linkedListSize(list))
    {
        fprintf(stderr, "input %d, add index must be between 0 and %d", index, linkedListSize(list));
        exit(0);
    }
}
void linkedListCheckIndex(LinkedList list, int index)
{
    checkNullPointer(list);
    if(index < 0 || index > linkedListSize(list) - 1)
    {
        fprintf(stderr, "input %d, remove index must be between 0 and %d", index, linkedListSize(list) - 1);
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
void linkedListInsert(LinkedList *list, int index, int val)
{
    linkedListCheckAddIndex(*list, index);
    LinkedList newNode;
    if(index == 0 && linkedListSize(*list) == 0 && (*list)->val == INIT_HEAD_VAL)
    {
        (*list)->val = val;
        return;
    }
    else if(index == 0)
    {
        newNode = malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = *list;
        *list = newNode;
        return;
    }
    else
    {
        newNode = malloc(sizeof(struct ListNode));
        newNode->val = val;
        ListNode preNode = *list;
        while(index > 1 && index--)
        {
            preNode = preNode->next;
        }
        newNode->next = preNode->next;
        preNode->next = newNode;
    }
}
void linkedListAdd(LinkedList list, int val)
{
    linkedListInsert(&list, linkedListSize(list), val);
}
void linkedListRemove(LinkedList *list, int index)
{
    linkedListCheckIndex(*list, index);
    if(index == 0)
    {
        ListNode tmp = *list;
        *list = (*list)->next;
        free(tmp);
        return;
    }
    else
    {
        ListNode tmp = *list;
        while(index > 1 && index--)
        {
            tmp =  tmp->next;
        }
        ListNode old = tmp->next;
        tmp->next = tmp->next->next;
        free(old);
    }

}
int linkedListSize(LinkedList list)
{
    checkNullPointer(list);
    if(list->val == INIT_HEAD_VAL) return 0;
    int size = 0;
    while(list->next)
    {
        size++;
        list = list->next;
    }
    return size + 1;
}
int linkedListGet(LinkedList list, int index)
{
    linkedListCheckIndex(list, index);
    if(!index) return list->val;
    while(index--) list = list->next;
    return list->val;
}

int linkedListGetIndex(LinkedList list, int val)
{
    checkNullPointer(list);
    int index = 0;
    while(list)
    {
        if(list->val == val) return index;
        else list = list->next;
        index++;
    }
    return -1;

}

void linkedListPrint(LinkedList list)
{
    fprintf(stdout, "length:%3d: [", linkedListSize(list));
    if(linkedListSize(list) == 0);
    else
    {
        fprintf(stdout, "%d", list->val);

        while(list->next)
        {
            fprintf(stdout, ",%d", list->next->val);
            list = list->next;
        }
    }
    fprintf(stdout, "]\n");
}
void linkedListSet(LinkedList list, int index, int val)
{
    linkedListCheckIndex(list, index);
    while(index--) list = list->next;
    list->val = val;
}
void LinkedListTest()
{
    LinkedList list;
    linkedListInit(&list);

    for(int i = 0; i < 20; i++)
        linkedListInsert(&list, i, i);
    linkedListPrint(list);

    linkedListRemove(&list, 19);
    linkedListRemove(&list, 0);
    linkedListPrint(list);

    linkedListSet(list, 0, 100);
    linkedListPrint(list);

}
