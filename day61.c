// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.
//
// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)
//
// Output:
// - n x n adjacency matrix
#include <stdio.h>
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int adj[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
            // adj[v][u] = 1; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}