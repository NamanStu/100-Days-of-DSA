/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>


void pallincheck(char*str){
    int start=0;
    int end=strlen(str)-1;

    while(start<end){
        if(str[start]!=str[end]){
            printf("NO");
            return;
        }
        start++;
        end--;
    }
    printf("YES");
    }


int main(){
char str[50];

printf("Enter a word:");
scanf("%s",str);

pallincheck(str);

    return 0;
}