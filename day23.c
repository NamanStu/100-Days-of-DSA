/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node*next;
};


struct node*create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct node*buildlist(int count){
    if(count==0) return NULL;
    int val;
    printf("Enter the value of node:");
    scanf("%d",&val);
    struct node*head=create(val);
    struct node*current=head;
    for(int i=1;i<count;i++){
        printf("Enter the value of %d node:",i);
        scanf("%d",&val);
        current->next=create(val);
        current=current->next;
    }
    return head;
}



struct node* mergeTwoLists(struct node* l1, struct node* l2) {
    struct node test; 
    struct node* tail = &test;
    tail->next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;

    return test.next;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter the number of nodes of list1:");
    if (scanf("%d", &n) != 1) return 0;
    struct node* list1 = buildlist(n);

    printf("Enter the number of nodes of list2:");
    if (scanf("%d", &m) != 1) return 0;
    struct node* list2 = buildlist(m);

    struct node* mergedHead = mergeTwoLists(list1, list2);
    printList(mergedHead);

    return 0;
}