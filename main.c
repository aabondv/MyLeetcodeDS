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
// disabuse
//����
//ָ��
//��ά����
//����ָ��
//����ָ��
//ָ������
//�����β���
int main()
{
    int a[] = {1, 2, 3};
    int *b = a;
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d ", *a++);
    }
    printf("\n");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d ", *b++);
    }

    return 0;
}
