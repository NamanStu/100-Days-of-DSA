/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int count;
} Candidate;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Candidate list[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);

        int found = 0;
        for (int j = 0; j < size; j++) {
            if (strcmp(list[j].name, temp) == 0) {
                list[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(list[size].name, temp);
            list[size].count = 1;
            size++;
        }
    }

    char winName[100];
    int winVotes = -1;

    for (int i = 0; i < size; i++) {
        if (list[i].count > winVotes) {
            winVotes = list[i].count;
            strcpy(winName, list[i].name);
        } else if (list[i].count == winVotes) {
            if (strcmp(list[i].name, winName) < 0) {
                strcpy(winName, list[i].name);
            }
        }
    }

    printf("%s %d\n", winName, winVotes);

    return 0;
}