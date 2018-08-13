#include "stdio.h"

void checkNullPointer(void * list)
{
    if(!list)
    {
        fprintf(stderr, "NULL pointer exception");
        exit(0);
    }
}
