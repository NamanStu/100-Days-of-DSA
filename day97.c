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

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void heapPush(int heap[], int* size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapPop(int heap[], int* size) {
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
}

int minMeetingRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    heapPush(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= heap[0])
            heapPop(heap, &size);

        heapPush(heap, &size, arr[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    printf("%d\n", minMeetingRooms(arr, n));

    return 0;
}