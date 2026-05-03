/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int key;
    struct node*next;
};

struct node*create(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL) return NULL;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void print_list(struct node**head){
    struct node*temp=*head;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int n_occ(struct node*head,int key){
    int count=0;
    struct node*temp=head;
    while(temp!=NULL){
         if(temp->data == key){
            count++;
        }
        temp=temp->next;
    }
    return count;
}
int main(){
    int n,val,key;
    struct node*head=NULL,*temp=NULL;
    
    printf("Enter size of list:");
    if(scanf("%d",&n)!=1)return 0;
    
    for(int i=0;i<n;i++){
        printf("Enter value of node %d:",i);
        scanf("%d",&val);
        struct node*newnode=create(val);

        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            temp=temp->next;
        }
    }
    print_list(&head);
    printf("\n");
    printf("Enter node to find occurances:");
    scanf("%d",&key);
    
    printf("%d\n",n_occ(head,key));
    return 0;
}