
#include "ArrayList.h"
#include "Common.h"
#include <stdio.h>

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
    checkNullPointer(list);
    *list = malloc(sizeof(struct ArrayList_));
    (*list)->node = malloc(DEFAULT_LIST_SIZE * sizeof(struct Node_));
    if(!(*list)->node) exit(0);
    (*list)->length = 0;
    (*list)->listSize = DEFAULT_LIST_SIZE;
}
void arrayListClear(ArrayList list)
{
    if(list)
    {
        memset(list->node, 0, list->length * sizeof(struct Node_));
        list->length = 0;
        //list->listSize = DEFAULT_LIST_SIZE;
    }
}
void arrayListDestory(ArrayList *list)
{
    if(list)
    {
        free((*list)->node);
        free(*list);
        *list = NULL;
    }
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
    checkIndex(list, index);
    for(int k = index; k < list->length; k++)
    {
         memcpy(list->node + k, list->node + k + 1, sizeof(struct Node_));
    }
    list->length--;

    //reduce capacity
    if(list->length > DEFAULT_LIST_SIZE && list->length < list->listSize / 2)
    {
        for(Node tmp = list->node + list->listSize / 2; tmp < list->node + list->listSize; tmp++)
            free(tmp);
        list->listSize /= 2;
        list->node = realloc(list->node, list->listSize * sizeof(struct Node_));
    }
}
void arrayListAdd(ArrayList list, void * data)
{
    checkNullPointer(list);
    arrayListInsert(list, list->length , data);
}

void* arrayListGet(ArrayList list, int index)
{
    checkIndex(list, index);
    return (list->node + index)->elem;
}

void arrayListSet(ArrayList list, int index, void *data)
{
    checkIndex(list, index);
    memcpy((list->node + index)->elem, data, sizeof(void *));
}
void arrayListPrint(ArrayList list)
{
    checkNullPointer(list);
    fprintf(stdout, "length:%3d, size:%3d: [", list->length, list->listSize);
    if(list->length == 0);
    else
    {
        int *tmp = arrayListGet(list, 0);
        printf("%d", *tmp);
        for(int i = 1; i < arrayListlength(list); i++)
        {
            tmp = arrayListGet(list, i);
            fprintf(stdout, ",%d", *tmp);
        }
    }
    fprintf(stdout, "]\n");

}

void ArrayListTest()
{
    ArrayList list;
   arrayListInit(&list);
   arrayListPrint(list);

   for(int i = 0; i < 20; i++)
   {
       arrayListAdd(list, &i);
   }
   arrayListPrint(list);

   for(int i = 0; i < 15; i++)
   {
       arrayListRemove(list, 0);
   }
   arrayListPrint(list);

   int data = 100;
   arrayListSet(list, 0, &data);
   arrayListPrint(list);

   arrayListClear(list);
   arrayListPrint(list);

   arrayListDestory(&list);
   arrayListPrint(list);
}
