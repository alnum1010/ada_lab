#include <stdio.h>

int cost[10][10];

int parent[10]; // Global parent array for union-find

int find(int i) {
    while (parent[i] != 0)
        i = parent[i];
    return i;
}

void uni(int i, int j) {
    parent[j] = i;
}

void kruskal(int n) {
    int a = 0, b = 0, u = 0, v = 0, ne = 1, i, j, min, mincost = 0;

    printf("The edges of minimum cost spanning tree:\n");
    
    // Initialize parent array
    for (i = 1; i <= n; i++)
        parent[i] = 0;

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
        u = find(u);
        v = find(v);
        
        if (u != v) {
            uni(u, v);
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        
        cost[a][b] = cost[b][a] = 999; // Mark the edge as processed
    }
    
    printf("\nMinimum cost: %d\n", mincost);
}

int main() {
    int i, j, n;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = 999; // Assuming 999 represents infinity or no edge
            }
        }
    }
    
    kruskal(n);
    
    return 0;
}
