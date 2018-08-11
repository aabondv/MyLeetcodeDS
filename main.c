#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

void arrayListPrint(ArrayList list)
{
    printf("[");
    if(list->length == 0);
    else
    {
        int *tmp = arrayListGetVal(list, 0);
        printf("%d", *tmp);
        for(int i = 1; i < arrayListlength(list); i++)
        {
            tmp = arrayListGetVal(list, i);
            printf(",%d", *tmp);
        }
    }
    printf("]\n");

}
int main()
{
   ArrayList list;
   arrayListInit(&list);

   int num[20] = {0,1,2,3,4,5,6,7,8,9};
   for(int i = 0; i < 2; i++)
   {
       arrayListAdd(list, &i);
   }
   arrayListPrint(list);
    return 0;
}
