/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int topo_order[MAX];
    int count = 0;

    if (scanf("%d %d", &n, &edges) != 2) return 0;

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int curr = queue[front++];
        topo_order[count++] = curr;

        for (int i = 0; i < n; i++) {
            if (adj[curr][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("Graph contains a cycle.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }

    return 0;
}