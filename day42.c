/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    printf("Enter number of elements in the queue: ");
    if (scanf("%d", &n) != 1) return;

    int *queue = (int *)malloc(n * sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &queue[i]);
    }

    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    for (int i = 0; i < n; i++) {
        printf("%d%s", queue[i], (i == n - 1 ? "" : " "));
    }
    printf("\n");

    free(queue);
    free(stack);
}

int main() {
    solve();
    return 0;
}