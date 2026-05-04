/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <limits.h>

#define MAX_EDGES 10000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int dist[1001];

int main() {
    int n, m, src;
    scanf("%d %d %d", &n, &m, &src);
    
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    
    for (int j = 0; j < m; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
    
    return 0;
}