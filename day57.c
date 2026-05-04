/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/
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

struct TreeNode* buildTree(int* nodes, int n) {
    if (n == 0 || nodes[0] == -1) return NULL;
    struct TreeNode* root = newNode(nodes[0]);
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];
        if (i < n && nodes[i] != -1) {
            curr->left = newNode(nodes[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && nodes[i] != -1) {
            curr->right = newNode(nodes[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void mirror(struct TreeNode* root) {
    if (!root) return;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int nodes[1000];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &nodes[i]);
    struct TreeNode* root = buildTree(nodes, n);
    mirror(root);
    inorder(root);
    return 0;
}