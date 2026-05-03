/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1; 
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            push(ch - '0'); 
        } else if (isOperator(ch)) {
            int val2 = pop();
            int val1 = pop();
            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            push(result);
        }
    }
    return pop(); 
}
int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}