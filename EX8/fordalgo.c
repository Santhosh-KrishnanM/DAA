#include <stdio.h>
#include <stdlib.h>

int dfs(int **rGraph, int V, int s, int t, int parent[], int visited[]) {
    visited[s] = 1;
    int v;
    if (s == t)
        return 1;

    for (v = 0; v < V; v++) {
        if (visited[v] == 0 && rGraph[s][v] > 0) {
            parent[v] = s;
            if (dfs(rGraph, V, v, t, parent, visited))
                return 1;
        }
    }

    return 0;
}

int fordFulkerson(int **graph, int V, int s, int t) {
    int u, v, i;
    int **rGraph = (int**)malloc(V * sizeof(int*));
    for (u = 0; u < V; u++) {
        rGraph[u] = (int*)malloc(V * sizeof(int));
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }
    int *parent = (int*)malloc(V * sizeof(int));
    int *visited = (int*)malloc(V * sizeof(int));
    int max_flow = 0;

    while (1) {
        for (i = 0; i < V; i++) {
            visited[i] = 0;
            parent[i] = -1;
        }

        if (!dfs(rGraph, V, s, t, parent, visited))
            break;

        int path_flow = 99999;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = (rGraph[u][v] < path_flow) ? rGraph[u][v] : path_flow;
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    free(parent);
    free(visited);
    for (u = 0; u < V; u++) {
        free(rGraph[u]);
    }
    free(rGraph);
    return max_flow;
}

int main() {
    int V, s, t, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int **graph = (int**)malloc(V * sizeof(int*));
    for (i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    printf("Enter the source vertex (0 to %d): ", V-1);
    scanf("%d", &s);
    printf("Enter the sink vertex (0 to %d, other than %d): ", V-1, s);
    scanf("%d", &t);
    if (t == s) {
        printf("Source and sink can't be the same.\n");
        exit(0);
    }

    printf("Enter the capacity of each edge (enter 0 for no edge):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i != j) {
                printf("Capacity from vertex %d to vertex %d: ", i, j);
                scanf("%d", &graph[i][j]);
            } else {
                graph[i][j] = 0;
            }
        }
    }

    printf("\nThe maximum possible flow is %d\n", fordFulkerson(graph, V, s, t));

    for (i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}