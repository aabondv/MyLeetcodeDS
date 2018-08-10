#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *List;
typedef struct ListNode *ListPosition;

void initList(List *list)
{
    *list = malloc(sizeof(struct ListNode));
    (*list)->next = NULL;
}


int list_size(struct ListNode* list)
{
    int size = 0;
    while(list->next)
    {
        size++;
        list = list->next;
    }
    return size + 1;
}
int main()
{

    return 0;
}
