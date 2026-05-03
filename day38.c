/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
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
    if (front == -1) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    while (n--) {
        char command[20];
        int value;
        printf("Enter operation: ");
        scanf("%s", command);
        if (strcmp(command, "push_front") == 0) {
            printf("Enter value to push at front: ");
            scanf("%d", &value);
            push_front(value);
        } else if (strcmp(command, "push_back") == 0) {
            printf("Enter value to push at back: ");
            scanf("%d", &value);
            push_back(value);
        } else if (strcmp(command, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(command, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(command, "front") == 0) {
            front_element();
        } else if (strcmp(command, "back") == 0) {
            back_element();
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        }
            else if (strcmp(command, "display") == 0) {
                display();
            } else {
                printf("Invalid command\n");
    }
}
    return 0;
}