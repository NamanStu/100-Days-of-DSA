/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees*/
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int search(int* inorder, int is, int ie, int val) {
    for (int i = is; i <= ie; i++)
        if (inorder[i] == val) return i;
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int ps, int pe, int is, int ie) {
    if (ps > pe || is > ie) return NULL;
    struct TreeNode* root = newNode(preorder[ps]);
    int mid = search(inorder, is, ie, preorder[ps]);
    int leftSize = mid - is;
    root->left = build(preorder, inorder, ps + 1, ps + leftSize, is, mid - 1);
    root->right = build(preorder, inorder, ps + leftSize + 1, pe, mid + 1, ie);
    return root;
}

void postorder(struct TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int preorder[1000], inorder[1000];
    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    struct TreeNode* root = build(preorder, inorder, 0, n - 1, 0, n - 1);
    postorder(root);
    return 0;
}