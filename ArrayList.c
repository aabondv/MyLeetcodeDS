
#include "ArrayList.h"
#include <stdio.h>

void checkNullPointer(ArrayList list)
{
    if(!list)
    {
        fprintf(stderr, "NULL pointer exception \n");
        exit(0);
    }
}
void checkIndex(ArrayList list, int index)
{
    checkNullPointer(list);
    if(!arrayListlength(list))
    {
        fprintf(stderr, "the list is empty!!!\n");
        exit(0);
    }
    else if(index < 0 || index >= arrayListlength(list))
    {
        fprintf(stderr, "index shoudle between 0 and %d: \n", arrayListlength(list) - 1, index);
        exit(0);
    }
}
void checkInsertIndex(ArrayList list, int index)
{
    checkNullPointer(list);
    if(!arrayListlength(list) && index )
    {
        fprintf(stderr, "error, the index  must be 0\n");
        exit(0);
    }
    else if(index < 0 || index > arrayListlength(list))
    {
        fprintf(stderr, "input error %d, insert before index, shoudle between 0 and %d\n", index, arrayListlength(list));
        exit(0);
    }
}
void arrayListInit(ArrayList *list)
{
    *list = malloc(sizeof(struct ArrayList_));
    (*list)->node = malloc(DEFAULT_LIST_SIZE * sizeof(struct Node_));
    if(!(*list)->node) exit(0);
    (*list)->length = 0;
    (*list)->listSize = DEFAULT_LIST_SIZE;
}
void arrayListClear(ArrayList list)
{

}
void arrayListInsert(ArrayList list, int index, void * data)
{
    checkInsertIndex(list, index);
    Node node = malloc(sizeof(struct Node_));

    node->elem = malloc(sizeof(void *));
    memcpy(node->elem, data, sizeof(void *));
    //node->elem = data; bug

    if(list->length == list->listSize)
    {
        list->listSize = list->listSize * 1.5;
        list->node = realloc(list->node, list->listSize * sizeof(struct Node_));
    }
    if(index == list->length) ;
    else
    {
         for(int k = list->length; k > index; k--)
         {
            memcpy(list->node + k, list->node + k - 1, sizeof(struct Node_));
         }
    }

    memcpy(list->node + index, node, sizeof(struct Node_));
    list->length++;
}
void arrayListRemove(ArrayList list, int index)
{
    checkNullPointer(list);
    checkIndex(list, index);
    //TODO
}
void arrayListAdd(ArrayList list, void * data)
{
    checkNullPointer(list);
    arrayListInsert(list, list->length , data);
}

void arrayListGet(ArrayList list, int index, void **data)
{
    checkNullPointer(list);
    checkIndex(list, index);
    void *val = (list->node + index)->elem;
    *data = val;
}
void* arrayListGetVal(ArrayList list, int index)
{
    checkNullPointer(list);
    checkIndex(list, index);
    return (list->node + index)->elem;
}
