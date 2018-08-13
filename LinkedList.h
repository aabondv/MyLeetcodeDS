#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct ListNode *LinkedList;
typedef struct ListNode *ListNode;

void linkedListInit(LinkedList *list);
void linkedListInsert(LinkedList list, int index, int val);
void linkedListAdd(LinkedList list, int val);
void linkedListRemove(LinkedList list, int index);
int linkedListSize(LinkedList list);
int linkedListGet(int index);



#endif // LINKEDLIST_H
