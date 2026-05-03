/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include <stdio.h>

int power(int num,int n){
    if(n==0){
        return 1;
    }
        return num*power(num,n-1);
}


int main(){

int num;
int n;
printf("Enter a number:");
scanf("%d",&num);

printf("Enter the power:");
scanf("%d",&n);

printf("Power: %d\n",power(num,n));




    return 0;
}