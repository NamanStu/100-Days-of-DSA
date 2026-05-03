/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void printlist(struct node** head) {
    struct node* temp = *head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data); 
        temp = temp->next;
    }
    printf("NULL\n");
}

void i_f(struct node** head) {
    int n;
    printf("Enter the value of newnode to insert at front: ");
    scanf("%d", &n);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n; 
    newnode->next = *head;
    newnode->prev = NULL; 

    if (*head != NULL) {
        (*head)->prev = newnode;
    }
    *head = newnode;
}

void i_l(struct node** head) {
    int n;
    printf("Enter the value to insert at last: ");
    scanf("%d", &n);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (*head == NULL) {
        newnode->prev = NULL;
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp; 
}

void i_p(struct node** head, int pos) {
    if (pos == 1) {
        i_f(head);
        return;
    }

    struct node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    int n;
    printf("Enter value for position %d: ", pos);
    scanf("%d", &n);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void d_f(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Front node deleted.\n");
}

void d_b(struct node** head) {
    if (*head == NULL) return;

    struct node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Back node deleted.\n");
}

void d_p(struct node** head, int pos) {
    if (*head == NULL) return;
    if (pos == 1) {
        d_f(head);
        return;
    }

    struct node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted.\n");
}

int main() {
    struct node* head = NULL;
    i_l(&head); 
    i_l(&head); 
    i_l(&head); 

    printf("Initial list: ");
    printlist(&head);

    i_f(&head);
    printlist(&head);

    int pos;
    printf("Enter position to insert node: ");
    scanf("%d", &pos);
    i_p(&head, pos);
    printlist(&head);

    d_f(&head);
    printlist(&head);

    d_b(&head);
    printlist(&head);

    printf("Enter position to delete node: ");
    scanf("%d", &pos);
    d_p(&head, pos);
    printlist(&head);

    return 0;
}