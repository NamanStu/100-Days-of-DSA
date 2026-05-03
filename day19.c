/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/
#include <stdio.h>


int absol(int n) {
    return (n < 0) ? -n : n;
}

void zeroclose(int arr[], int n) {
    if (n < 2) return;

    for (int i = 0; i < n - 1; i++) {
        int min_el = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_el]) {
                min_el = j;
            }
        }
        int temp = arr[min_el];
        arr[min_el] = arr[i];
        arr[i] = temp;
    }

    int left = 0;
    int right = n - 1;
    
    int res_l = left, res_r = right;
    int min_sum = arr[left] + arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (absol(sum) < absol(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        if (sum < 0) {
            left++; 
        } else if (sum > 0) {
            right--; 
        } else {
            break; 
        }
    }

    printf("%d %d\n", arr[res_l], arr[res_r]);
}

int main() {
    int n;
    printf("Enter the size of array:");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the %d value of array:",i);
        scanf("%d", &arr[i]);
    }

    zeroclose(arr, n);
    return 0;
}