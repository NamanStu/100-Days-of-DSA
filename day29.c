/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

void printlist(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
struct node*createnode(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node*rotateright(struct node*head,int k,int n){
    if(head==NULL||k==0)return head;
    k=k%n;
    if(k==0)return head;

    struct node*temp=head;
    int count=1;
    while(count<n){
        temp=temp->next;
        count++;
    }
    temp->next=head;

    temp=head;
    for(int i=1;i<n-k;i++){
        temp=temp->next;
    }
    struct node*newhead=temp->next;
    temp->next=NULL;

    return newhead;
}
int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    struct node*head=NULL;
    struct node*tail=NULL;
    printf("Enter node values: ");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        struct node*newnode=createnode(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    int k;
    printf("Enter number of rotations: ");
    scanf("%d",&k);
    head=rotateright(head,k,n);
    printf("Rotated List: ");
    printlist(head);
    return 0;
}