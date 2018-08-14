#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#define BITREE_NULL -1


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
typedef struct TreeNode * BiTree;

void binaryTreeInit(BiTree *tree, int num[], int cur, int size);

int binaryTreeMaxDeep(BiTree tree);

void binaryTreePreOrderTraverse(BiTree tree);

void binaryTreeInOrderTraverse(BiTree tree);

void binaryTreePostOrderTraverse(BiTree tree);

#endif // BINARYTREE_H
