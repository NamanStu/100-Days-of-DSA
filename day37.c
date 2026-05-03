/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    if (size >= MAX) return;
    heap[size] = x;
    int curr = size;
    size++;
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (heap[curr] < heap[parent]) {
            swap(&heap[curr], &heap[parent]);
            curr = parent;
        } else break;
    }
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    int curr = 0;
    while (1) {
        int smallest = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != curr) {
            swap(&heap[curr], &heap[smallest]);
            curr = smallest;
        } else break;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
}

int main() {
    int n;
    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        char op[10];
        printf("Enter operation: ");
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            printf("Enter value to insert: ");
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}