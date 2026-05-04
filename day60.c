// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.
//
// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal
//
// Output Format:
// - Print YES if valid Min-Heap, otherwise NO
//
// Example:
// Input:
// 7
// 1 3 5 7 9 8 10
//
// Output:
// YES
//
// Explanation:
// Each parent node must be smaller than its children.
#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[i] > arr[leftChild]) {
            return false;
        }

        if (rightChild < n && arr[i] > arr[rightChild]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}