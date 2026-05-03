/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void update_frequency(Node* table[], int key) {
    int index = hash(key);
    Node* temp = table[index];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = table[index];
    table[index] = newNode;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    Node* table[TABLE_SIZE] = {NULL};
    int nums[n];

    for (int i = 0; i < n; i++) {
        printf("Enter %d element of array:",i);
        scanf("%d", &nums[i]);
        update_frequency(table, nums[i]);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table[i];
        while (temp) {
            printf("%d:%d ", temp->key, temp->count);
            temp = temp->next;
        }
    }

    return 0;
}