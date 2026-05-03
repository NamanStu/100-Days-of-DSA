/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

void traverse_list(struct node**head){
    struct node*temp=*head;
    while(temp->next!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}



int main(){

struct node*head=(struct node*)malloc(sizeof(struct node));
struct node*n1=(struct node*)malloc(sizeof(struct node));
struct node*n2=(struct node*)malloc(sizeof(struct node));
struct node*n3=(struct node*)malloc(sizeof(struct node));
struct node*n4=(struct node*)malloc(sizeof(struct node));

head->data=10;
head->next=n1;
n1->data=20;
n1->next=n2;
n2->data=30;
n2->next=n3;
n3->data=30;
n3->next=NULL;

traverse_list(&head);



    return 0;
}
