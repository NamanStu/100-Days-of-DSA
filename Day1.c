// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

// Example:
// Input:
// 5
// 1 2 4 5 6
// 3
// 3

// Output:
// 1 2 3 4 5 6

// Explanation: Insert 3 at position 3, elements [4,5,6] shift right


#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=5;
    int num,pos;
    int*arr;
    arr=(int*)malloc(n*sizeof(int));
    if(arr == NULL){
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("Enter %d element of array:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("ARRAY: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("Enter number to insert:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);

    n++;
    arr=(int*)realloc(arr,n*sizeof(int));

    for(int i=n-1; i<pos ; i++){
        arr[i]=arr[i-1];
    }
    arr[pos]=num;
   printf("ARRAY AFTER INSERTION:");
   for(int i=0;i<n;i++){
     printf("%d\t",arr[i]);
   }
   free(arr);
   
   return 0;

}