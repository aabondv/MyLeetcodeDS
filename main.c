#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

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
int main()
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

   return 0;
}
