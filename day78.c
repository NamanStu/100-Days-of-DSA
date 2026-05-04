/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int adj[MAX][MAX];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            adj[i][j] = INT_MAX;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int count = 0; count < n; count++) {
        int min = INT_MAX, u;

        for (int v = 1; v <= n; v++)
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                u = v;
            }

        mstSet[u] = true;

        for (int v = 1; v <= n; v++)
            if (adj[u][v] != INT_MAX && mstSet[v] == false && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }

    int totalWeight = 0;
    for (int i = 2; i <= n; i++)
        totalWeight += key[i];

    printf("%d\n", totalWeight);

    return 0;
}