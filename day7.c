/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/

#include <stdio.h>

int fibo(int num){
    for(int i=num;i>=0;i++){
        if(i==0){
            return 0;
        }
        if(i==1){
            return 1;
        }

        else{
            return fibo(i-1)+fibo(i-2);
        }
    }


}


int main(){

    int n;
    printf("Enter an number:");
    scanf("%d",&n);

    printf("Nth fibbonaci number: %d",fibo(n));



    return 0;
}