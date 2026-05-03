/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int value){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=value;
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    top--;
}
void display(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    int n,m;
    printf("Enter number of elements to push: ");
    scanf("%d",&n);
    printf("Enter elements to push: ");
    for(int i=0;i<n;i++){
        int value;
        scanf("%d",&value);
        push(value);
    }
    printf("Enter number of pops: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        pop();
    }
    printf("Remaining stack elements: ");
    display();
    return 0;
}