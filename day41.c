/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}
void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }
    Node* temp = q->front;
    printf("%d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}
void display(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    int N;
    printf("Enter number of operations: ");
    scanf("%d", &N);
    char command[20];
    int x;
    for (int i = 0; i < N; i++) {
        printf("Enter operation: ");
        scanf("%s", command);
        if (strcmp(command, "enqueue") == 0) {
            printf("Enter value to enqueue: ");
            scanf("%d", &x);
            enqueue(&q, x);
        } else if (strcmp(command, "dequeue") == 0) {
            dequeue(&q);
        }
        else if (strcmp(command, "display") == 0) {
            display(&q);
        }
    }
    return 0;
}