#include<stdio.h>
#include<stdlib.h>
void inorder(struct TreeNode* root, int* arr, int* i)
{
    if(root == NULL)
        return;

    inorder(root->left, arr, i);

    arr[*i] = root->val;
    (*i)++;

    inorder(root->right, arr, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *arr = (int*)malloc(100 * sizeof(int));
    int i = 0;

    inorder(root, arr, &i);

    *returnSize = i;
    return arr;
}