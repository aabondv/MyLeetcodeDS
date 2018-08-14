#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "BinaryTree.h"
int main()
{

//    fprintf(stdout, "----------ArrayList Test---------");
//    ArrayListTest();
//    fprintf(stdout, "----------LinkedList Test---------");
//    LinkedListTest();
    int a[] = {0, 1, 2, 3, -1, -1, 4};
    BiTree tree;
    binaryTreeInit(&tree, a, 0, ArraySize(a));
    binaryTreePreOrderTraverse(tree);
    fprintf(stdout, "\n");
    binaryTreeInOrderTraverse(tree);
    fprintf(stdout, "\n");
    binaryTreePostOrderTraverse(tree);
    fprintf(stdout, "\n");
    return 0;
}
