/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*createnode(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}

void printlist(struct node**head){
    struct node*temp=*head;

    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void delete_node(struct node**head,int key){
struct node*temp=*head,*prev=NULL;
while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp); 
}


int main(){

struct node*head=createnode(10);
struct node*n1=createnode(20);
struct node*n2=createnode(30);
struct node*n3=createnode(40);
struct node*n4=createnode(50);

head->next=n1;
n1->next=n2;
n2->next=n3;
n3->next=n4;
n4->next=NULL;

int key=30;

printlist(&head);
delete_node(&head,key);
printf("\n");
printlist(&head);



    return 0;
}