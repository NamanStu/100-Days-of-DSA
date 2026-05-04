/*roblem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>

int canPaint(int boards[], int n, int k, long long mid) {
    int paintersCount = 1;
    long long currentBoardSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > mid) return 0;
        if (currentBoardSum + boards[i] > mid) {
            paintersCount++;
            currentBoardSum = boards[i];
            if (paintersCount > k) return 0;
        } else {
            currentBoardSum += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}