#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//head node in leetcode linkedlist storage value
struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct ListNode *LinkedList;
typedef struct ListNode *ListNode;

void linkedListInit(LinkedList *list);
void linkedListInsert(LinkedList *list, int index, int val);
void linkedListAdd(LinkedList list, int val);
void linkedListRemove(LinkedList *list, int index);
int linkedListSize(LinkedList list);
int linkedListGet(LinkedList list, int index);
void linkedListSet(LinkedList list, int index, int val);



#endif // LINKEDLIST_H
