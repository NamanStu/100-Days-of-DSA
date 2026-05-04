/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    if (data == -1) return NULL;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct node* root = newNode(arr[0]);
    struct node** queue = malloc(sizeof(struct node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n && head < tail) {
        struct node* current = queue[head++];
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }
    free(queue);
    return root;
}

int res[1000][1000];
int sizes[1000] = {0};
int max_level = 0;

void fillLevels(struct node* root, int level) {
    if (!root) return;
    if (level > max_level) max_level = level;
    res[level][sizes[level]++] = root->data;
    fillLevels(root->left, level + 1);
    fillLevels(root->right, level + 1);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *arr = malloc(sizeof(int) * n);
    printf("Enter the level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);
    fillLevels(root, 0);

    for (int i = 0; i <= max_level; i++) {
        if (sizes[i] == 0) continue;
        if (i % 2 == 0) {
            for (int j = 0; j < sizes[i]; j++) printf("%d", res[i][j]);
        } else {
            for (int j = sizes[i] - 1; j >= 0; j--) printf("%d", res[i][j]);
        }
    }

    free(arr);
    return 0;
}