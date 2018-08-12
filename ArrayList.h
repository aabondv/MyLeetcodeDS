#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define DEFAULT_LIST_SIZE 10

struct Node_{
    void * elem;
};
typedef struct Node_ *Node;

struct ArrayList_{
    Node node;
    int length;
    int listSize;
};
typedef struct ArrayList_ *ArrayList;

/** \brief initialise a ArrayList
 *
 * \param  a ArrayList  pointer
 *
 * \return None
 */

void arrayListInit(ArrayList *list);

void arrayListClear(ArrayList list);

void arrayListDestory(ArrayList *list);

void arrayListInsert(ArrayList list, int index, void * data);

void arrayListRemove(ArrayList list, int index);

void arrayListAdd(ArrayList list, void * data);

void* arrayListGet(ArrayList list, int index);

void arrayListSet(ArrayList list, int index, void *data);

#define arrayListSize(list) (list->listSize)
#define arrayListlength(list) (list->length)
#define arrayListIsEmpty(list) (list->length == 0)



#endif // ARRAYLIST_H
