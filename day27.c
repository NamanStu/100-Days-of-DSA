/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void findIntersection(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;

    while (ptr1 != NULL) {
        struct node* ptr2 = head2;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                printf("OUTPUT:%d\n", ptr1->data);
                return; 
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m, val;
    struct node *head1 = NULL, *tail1 = NULL;
    struct node *head2 = NULL, *tail2 = NULL;

    printf("Enter n, the size of linked list 1: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter list 1 elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node* newNode = createNode(val);
        if (!head1) head1 = newNode;
        else tail1->next = newNode;
        tail1 = newNode;
    }

    printf("Enter m,the size of linked list 2: ");
    if (scanf("%d", &m) != 1) return 0;

    printf("Enter list 2 elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct node* newNode = createNode(val);
        if (!head2) head2 = newNode;
        else tail2->next = newNode;
        tail2 = newNode;
    }

    findIntersection(head1, head2);

    return 0;
}