/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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
struct node* insertLevelOrder(int arr[], struct node* root, int i, int n){
    if(i<n){
        struct node* temp = newNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2*i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2*i + 2, n);
    }
    return root;
}
struct node* lca(struct node* root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;
    struct node* left_lca=lca(root->left,n1,n2);
    struct node* right_lca=lca(root->right,n1,n2);
    if(left_lca && right_lca) return root;
    return (left_lca!=NULL)? left_lca : right_lca;
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    if(scanf("%d",&n)!=1 || n<=0){
        printf("0\n");
        return 0;
    }
    int arr[n];
    printf("Enter the level-order traversal (-1 for NULL): ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct node* root=NULL;
    root=insertLevelOrder(arr,root,0,n);
    int n1,n2;
    printf("Enter the two node values: ");
    scanf("%d %d",&n1,&n2);
    struct node* lca_node=lca(root,n1,n2);
    if(lca_node) printf("%d\n",lca_node->data);
    else printf("0\n");
    return 0;
}