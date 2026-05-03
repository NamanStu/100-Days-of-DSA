/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include <stdio.h>
#include <string.h>
#define MAX 1000
int deque[MAX];
int front = -1, rear = -1;
void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}
void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}
void pop_front() {
    if (front == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}
void pop_back() {
    if (rear == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}
void front_element() {
    if (front == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
}
void back_element() {
    if (rear == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
}
int empty() {
    return front == -1;
}
int size() {
    if (front == -1) {
        return 0;
    }
    if (rear >= front) {
        return rear - front + 1;
    }
    return MAX - front + rear + 1;
}
void min_element() {
    if (front == -1) {
        printf("-1\n");
        return;
    }
    int min = deque[front];
    for (int i = 1; i < size(); i++) {
        int index = (front + i) % MAX;
        if (deque[index] < min) {
            min = deque[index];
        }
    }
    printf("%d\n", min);
}
int main() {
    int N;
    printf("Enter number of operations: ");
    scanf("%d", &N);
    char command[20];
    int x;
    for (int i = 0; i < N; i++) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            printf("Enter value to insert: ");
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(command, "extractMin") == 0) {
           min_element();
        } else if (strcmp(command, "peek") == 0) {
            front_element();
        }
    }
    return 0;
}