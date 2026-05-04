#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct QNode {
    struct node* treeNode;
    int hd; 
};


struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

void verticalOrder(struct node* root, int n) {
    if (!root) return;

    int* vertical[2001];
    int count[2001] = {0};

    for (int i = 0; i < 2001; i++) {
        vertical[i] = (int*)malloc(n * sizeof(int));
    }

    struct QNode queue[2001];
    int front = 0, rear = 0;

    queue[rear++] = (struct QNode){root, 0};

    int min_hd = 0, max_hd = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct node* curr = temp.treeNode;
        int hd = temp.hd;

        int index = hd + 1000;

        vertical[index][count[index]++] = curr->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (curr->left) {
            queue[rear++] = (struct QNode){curr->left, hd - 1};
        }

        if (curr->right) {
            queue[rear++] = (struct QNode){curr->right, hd + 1};
        }
    }

    for (int i = min_hd + 1000; i <= max_hd + 1000; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", vertical[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    scanf("%d", &n);

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n, 0);

    verticalOrder(root, n);

    return 0;
}