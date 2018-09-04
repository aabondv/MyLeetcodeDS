#include "hashtable.h"


void hashTableInit(HashTable *table, int length)
{
    *table = malloc(sizeof(struct HashTable));
    (*table)->list = (LinkedList *)malloc(length * sizeof(LinkedList));
    (*table)->length = length;
    for (int i = 0; i < (*table)->length; i++)
        linkedListInit(&((*table)->list[i]));
}

int hashTableIndex(HashTable table, int data)
{
    return data % table->length;
}

void hashTableInsert(HashTable table, int data)
{
    if(hashTableLookup(table, data))
    {
        int index = hashTableIndex(table, data);
        LinkedList list = table->list[index];
        linkedListAdd(list, data);
    }


}
void hashTableRemove(HashTable table, int data)
{
    if(!hashTableLookup(table, data))
    {
        int index = hashTableIndex(table, data);
        LinkedList list = table->list[index];
        int listIndex = linkedListGetIndex(list, data);
        //change linkedlist head address
        linkedListRemove(&table->list[index], listIndex);
    }
}

int hashTableLookup(HashTable table, int data)
{
    int index = hashTableIndex(table, data);
    LinkedList list = table->list[index];
    if((linkedListSize(list)) == 0)
        return 1;//not exist
    else
    {
        while(list)
        {
            if(list->val == data) return 0;//exist
            list = list->next;
        }
        return 1;
    }
}

void hashTableTest()
{
    HashTable table;
    hashTableInit(&table, 100);

    for(int i = 0; i < 1000; i++)
        hashTableInsert(table, i);

    for(int i = 0; i < 10; i++)
    {
        hashTableRemove(table, i * 10);
        printf("%d\n", hashTableLookup(table, i * 10));
    }
}
