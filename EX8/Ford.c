#include <stdio.h>
#include <stdlib.h>

// DFS to find augmenting path
int dfs(int **rGraph, int V, int s, int t, int parent[], int visited[]) {
    // Mark the current node as visited
    visited[s] = 1;
    
    // If we reached the sink, return true
    if (s == t)
        return 1;
    
    // Try all adjacent vertices
    for (int v = 0; v < V; v++) {
        // If vertex is not visited and has capacity
        if (visited[v] == 0 && rGraph[s][v] > 0) {
            // Store this path
            parent[v] = s;
            
            // Recursively find path from v to t
            if (dfs(rGraph, V, v, t, parent, visited))
                return 1;
        }
    }
    
    // No path found from s to t
    return 0;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int **graph, int V, int s, int t) {
    int u, v;

    // Create a residual graph and fill it with given capacities as
    // residual capacities of original graph
    int **rGraph = (int**)malloc(V * sizeof(int*));
    for (u = 0; u < V; u++) {
        rGraph[u] = (int*)malloc(V * sizeof(int));
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int *parent = (int*)malloc(V * sizeof(int)); // Array to store path
    int *visited = (int*)malloc(V * sizeof(int)); // Array to track visited nodes
    
    int max_flow = 0; // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink
    while (1) {
        // Initialize visited and parent arrays
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            parent[i] = -1;
        }
        
        // Try to find an augmenting path using DFS
        if (!dfs(rGraph, V, s, t, parent, visited))
            break; // No more augmenting paths
            
        // Find minimum residual capacity of the edges along the
        // path found by DFS
        int path_flow = 99999;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = (rGraph[u][v] < path_flow) ? rGraph[u][v] : path_flow;
        }

        // Update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Free dynamically allocated memory
    free(parent);
    free(visited);
    for (u = 0; u < V; u++) {
        free(rGraph[u]);
    }
    free(rGraph);

    // Return the overall flow (max_flow)
    return max_flow;
}

// Driver program to test above functions
int main() {
    int V, s, t;
    
    // Get the number of vertices
    printf("Enter the no. of vertices:");
    scanf("%d", &V);
    
    // Dynamically allocate memory for the graph
    int **graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }
    
    // Get the source and sink vertices
    printf("Enter the source vertex (0 to %d): ", V-1);
    scanf("%d", &s);
    printf("Enter the sink vertex (0 to %d, other than %d): ", V-1, s);
    scanf("%d", &t);
    if(t==s){
        printf("Source and sink can't be same.\n");
        exit(0);
    }
    
    // Input the capacity of each edge
    printf("Enter the capacity of each edge (enter 0- no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if(i != j) {
                printf("Capacity from vertex %d to vertex %d: ", i, j);
                scanf("%d", &graph[i][j]);
            }
            else
                graph[i][j] = 0;
        }
    }
    
    // Calculate and print the maximum flow
    printf("\nThe maximum possible flow is %d\n", fordFulkerson(graph, V, s, t));
    
    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}