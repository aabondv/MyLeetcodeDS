#include "BinaryTree.h"

void binaryTreeInit(BiTree *tree, int num[], int cur, int size)
{
    if(cur > size - 1 || num[cur] == BITREE_NULL)
    {
        *tree = NULL;
        return;
    }
    *tree = malloc(sizeof(struct TreeNode));
    (*tree)->val = num[cur];
    binaryTreeInit(&(*tree)->left, num, cur * 2 + 1, size);
    binaryTreeInit(&(*tree)->right, num, cur * 2 + 2, size);
}
int binaryTreeMaxDeep(BiTree tree)
{
    if(!tree)
        return 0;
    int left = binaryTreeMaxDeep(tree->left) + 1;
    int right = binaryTreeMaxDeep(tree->right) + 1;
    return MAX(left, right);
}
void binaryTreeVisit(BiTree tree)
{
    fprintf(stdout,"%d ", tree->val);
}
void binaryTreePreOrderTraverse(BiTree tree)
{
    if(tree)
    {
        binaryTreeVisit(tree);
        binaryTreePreOrderTraverse(tree->left);
        binaryTreePreOrderTraverse(tree->right);
    }
}

void binaryTreeInOrderTraverse(BiTree tree)
{
    if(tree)
    {
        binaryTreeInOrderTraverse(tree->left);
        binaryTreeVisit(tree);
        binaryTreeInOrderTraverse(tree->right);
    }
}

void binaryTreePostOrderTraverse(BiTree tree)
{
    if(tree)
    {
        binaryTreePostOrderTraverse(tree->left);
        binaryTreePostOrderTraverse(tree->right);
        binaryTreeVisit(tree);
    }
}
