/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool stack[MAX];
int V, E;

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        visited[v] = true;
        stack[v] = true;

        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return true;
                else if (stack[i])
                    return true;
            }
        }
    }
    stack[v] = false;
    return false;
}

bool isCyclic() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        stack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (isCyclicUtil(i))
            return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}