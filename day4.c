/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays*/

#include <stdio.h>
#include <stdlib.h>


int main(){


int n;
printf("Enter the size of array:");
scanf("%d",&n);

int *arr;
arr=(int*)malloc(n*sizeof(int));

for(int i=0;i<n;i++){
    printf("Enter %d element of array:",i);
    scanf("%d",&arr[i]);
}

printf("Array:");
for(int i=0;i<n;i++){
    printf(" %d\t ",arr[i]);
}

int start=0;
int end=n-1;

while(start<end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;

}

printf("Array after reversal :");
for(int i=0;i<n;i++){
    printf(" %d\t ",arr[i]);
}

    return 0;
}