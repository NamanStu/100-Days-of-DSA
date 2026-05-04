/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int target, weight;
    struct Edge* next;
};

struct Node {
    int vertex, dist;
};

struct MinHeap {
    struct Node* array;
    int size, capacity;
};

struct Edge* newEdge(int target, int weight, struct Edge* next) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->target = target;
    edge->weight = weight;
    edge->next = next;
    return edge;
}

struct MinHeap* createHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (struct Node*)malloc(capacity * sizeof(struct Node));
    return heap;
}

void swap(struct Node* a, struct Node* b) {
    struct Node t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left].dist < heap->array[smallest].dist)
        smallest = left;
    if (right < heap->size && heap->array[right].dist < heap->array[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->array[smallest], &heap->array[idx]);
        heapify(heap, smallest);
    }
}

void push(struct MinHeap* heap, int v, int dist) {
    heap->array[heap->size].vertex = v;
    heap->array[heap->size].dist = dist;
    int i = heap->size++;
    while (i && heap->array[i].dist < heap->array[(i - 1) / 2].dist) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Node pop(struct MinHeap* heap) {
    struct Node root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify(heap, 0);
    return root;
}

void dijkstra(struct Edge** adj, int V, int src) {
    int* dist = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;

    struct MinHeap* pq = createHeap(V * V);
    dist[src] = 0;
    push(pq, src, 0);

    while (pq->size) {
        struct Node node = pop(pq);
        int u = node.vertex;

        if (node.dist > dist[u]) continue;

        for (struct Edge* e = adj[u]; e; e = e->next) {
            if (dist[u] + e->weight < dist[e->target]) {
                dist[e->target] = dist[u] + e->weight;
                push(pq, e->target, dist[e->target]);
            }
        }
    }

    for (int i = 0; i < V; i++) printf("%d: %d\n", i, dist[i]);
    free(dist);
    free(pq->array);
    free(pq);
}

int main() {
    int V = 5;
    struct Edge** adj = (struct Edge**)calloc(V, sizeof(struct Edge*));

    adj[0] = newEdge(1, 9, newEdge(2, 6, adj[0]));
    adj[1] = newEdge(3, 3, newEdge(4, 2, adj[1]));
    adj[2] = newEdge(1, 2, newEdge(3, 1, adj[2]));
    adj[3] = newEdge(4, 5, adj[3]);

    dijkstra(adj, V, 0);

    return 0;
}