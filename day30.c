/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node*next;
};


struct node*create(int coeff,int exp){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode;
}

void printlist(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coeff,temp->exp);
        temp=temp->next;
        if(temp!=NULL)printf(" + ");
    }
    printf("\n");
    printf("NULL\n");
}
int main(){

struct node*head=create(10,4);
head->next=create(20,3);
head->next->next=create(30,2);
head->next->next->next=create(40,1);
head->next->next->next->next=create(50,0);
printlist(head);

    return 0;
}