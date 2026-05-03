/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char value){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=value;
}
char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}
int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}
void infixToPostfix(char* infix, char* postfix){
    int j=0;
    for(int i=0; infix[i]!='\0'; i++){
        char ch=infix[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
            postfix[j++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++]=pop();
            }
            pop(); 
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; 
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}