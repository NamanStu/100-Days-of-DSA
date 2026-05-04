/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    if (scanf("%s", s) != 1) return 0;

    int visited[256] = {0};
    char result = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        if (visited[(unsigned char)s[i]] == 1) {
            result = s[i];
            break;
        }
        visited[(unsigned char)s[i]] = 1;
    }

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}