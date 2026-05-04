#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int k = 0;

    result[k++] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[k-1].end) {
            if (arr[i].end > result[k-1].end)
                result[k-1].end = arr[i].end;
        } else {
            result[k++] = arr[i];
        }
    }

    for (int i = 0; i < k; i++)
        printf("%d %d\n", result[i].start, result[i].end);

    return 0;
}