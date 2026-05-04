/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node* newNode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* insert(struct node* root,int data){
    if(root==NULL) return newNode(data);
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    return root;
}
struct node* lca(struct node* root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data>n1 && root->data>n2) return lca(root->left,n1,n2);
    if(root->data<n1 && root->data<n2) return lca(root->right,n1,n2);
    return root;
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    if(scanf("%d",&n)!=1 || n<=0){
        printf("0\n");
        return 0;
    }
    struct node* root=NULL;
    for(int i=0;i<n;i++){
        int data;
        printf("Enter node value: ");
        scanf("%d",&data);
        root=insert(root,data);
    }
    int n1,n2;
    printf("Enter two node values to find LCA: ");
    scanf("%d %d",&n1,&n2);
    struct node* ancestor=lca(root,n1,n2);
    if(ancestor) printf("LCA: %d\n",ancestor->data);
    else printf("LCA not found\n");
    return 0;
}