/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.
Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/

#include <stdio.h>

int main(){
int n;
printf("Enter the Size of array:");
scanf("%d",&n);
int nums[n];
for(int i=0;i<n;i++){
    printf("Enter the %d element of array:",i);
    scanf("%d",&nums[i]);
}
printf("ARRAY:");
for(int i=0;i<n;i++){
    printf("%d\t",nums[i]);
}
int maxel=nums[0];
int minel=nums[0];

for(int i=0;i<n;i++){
  if(nums[i]>maxel){
    maxel=nums[i];
  }
    if(nums[i]<minel){
        minel=nums[i];
    }
}

printf("Maximum element of array:%d\n, Minimum element of array:%d\n",maxel,minel);


return 0;
}