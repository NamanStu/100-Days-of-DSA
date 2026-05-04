/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int to;
    int weight;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} AdjList;

void add_edge(AdjList *graph, int u, int v, int w) {
    if (graph[u].size == graph[u].capacity) {
        graph[u].capacity = graph[u].capacity == 0 ? 1 : graph[u].capacity * 2;
        graph[u].edges = realloc(graph[u].edges, graph[u].capacity * sizeof(Edge));
    }
    graph[u].edges[graph[u].size++] = (Edge){v, w};
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    AdjList *graph = calloc(n + 1, sizeof(AdjList));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(graph, u, v, w);
        add_edge(graph, v, u, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    bool visited[MAX];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }

        if (dist[u] == INT_MAX) break;
        visited[u] = true;

        for (int j = 0; j < graph[u].size; j++) {
            Edge e = graph[u].edges[j];
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d%c", dist[i], i == n ? '\n' : ' ');
    }

    return 0;
}