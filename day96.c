#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv = 0;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid + 1, right);
    }
    return inv;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", result);

    return 0;
}