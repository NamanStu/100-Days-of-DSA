/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) {
        return 1;
    }
    if (left == NULL || right == NULL) {
        return 0;
    }
    return (left->data == right->data) &&
     isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
int isSymmetric(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    return isMirror(root->left, root->right);
}
struct Node* buildTree(int* arr, int n) {
    if (n == 0) {
        return NULL;
    }
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
    }    return root;
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}