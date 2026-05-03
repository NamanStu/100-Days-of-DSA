/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void VJ_printlist(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}

void VJ_i_p(struct node** head, int pos) {
    if (pos == 1) {
        return;
    }

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
      
        if (temp == *head) {
            printf("Position Out of Bounds\n");
            return;
        }
    }

    int n;
    printf("Enter value for position %d: ", pos);
    scanf("%d", &n);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    
   
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Inserted %d at position %d\n", n, pos);
}


void VJ_d_p(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

  
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            printf("Position Out of Bounds\n");
            return;
        }
    }

   
    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}


void VJ_i_f(struct node** head) {
    int n;
    printf("Enter the value to insert at first: ");
    scanf("%d", &n);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
        return;
    }
    struct node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    newnode->next = *head;
    temp->next = newnode;
    *head = newnode;
}

int main() {

    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));

    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = head;

    printf("Initial List: ");
    VJ_printlist(head);

   
    VJ_i_p(&head, 3);
    VJ_printlist(head);

    VJ_d_p(&head, 3); 
    VJ_printlist(head);

    return 0;
}