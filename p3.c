//Part-a
#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX // Infinity value for unreachable vertices

void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d   ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];

    // Initialize the distance matrix with the given graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update the distance matrix by considering all intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

int main() {
    /* Example graph
            0      5     INF     10
          INF      0      3     INF
          INF    INF     0       1
          INF    INF    INF      0   */
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    floydWarshall(graph);

    return 0;
}



//Part-b
#include <stdio.h>

#define V 4 

void printTransitiveClosure(int tc[][V]) {
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", tc[i][j]);
        }
        printf("\n");
    }
}

void transitiveClosure(int graph[][V]) {
    int tc[V][V];

    // Initialize the transitive closure matrix with the given graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            tc[i][j] = graph[i][j];
        }
    }

    // Update the transitive closure matrix using Warshall's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);
            }
        }
    }

    printTransitiveClosure(tc);
}

int main() {
    /* Example graph
            1       1       0       1
            0       1       1       0
            0       0       1       1
            0       0       0       1   */
    int graph[V][V] = {{1, 1, 0, 1},
                       {0, 1, 1, 0},
                       {0, 0, 1, 1},
                       {0, 0, 0, 1}};

    transitiveClosure(graph);

    return 0;
}
