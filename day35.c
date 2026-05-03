/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value){
    if(front - rear == 1){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
}
void display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void dequeue(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = rear = -1;
    } else {
        front++;
    }
}
int main() {
    display();
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Queue elements: ");
    display();
    return 0;
}