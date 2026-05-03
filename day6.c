/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/

#include <stdio.h>
#include <stdlib.h>

int main(){

int n;
printf("Enter size of array:");
scanf("%d",&n);

if(n!=1 && n<=0){
    return 0;
}


int *arr;
arr=(int*)malloc(n*sizeof(int));


for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}


printf("%d",arr[0]);

for(int i=1;i<n;i++){
    if(arr[i]!=arr[i-1]){
        printf("%d",arr[i]);
    }
}

free(arr);

    return 0;
}