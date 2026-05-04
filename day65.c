/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V, E;

bool isCycle(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (isCycle(i, v))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    if (scanf("%d %d", &V, &E) != 2) return 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    bool cycleFound = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycle(i, -1)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound) printf("YES\n");
    else printf("NO\n");

    return 0;
}