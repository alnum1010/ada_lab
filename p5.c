#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;
void createGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        } }}
void topoSort() {
    int indegree[MAX];
    int i, j, k;
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (adj[j][i] != 0) {
                indegree[i]++;
            } } }
    printf("Topological sorting order: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (indegree[j] == 0 && !visited[j]) {
                printf("%d ", j);
                visited[j] = 1;
 
                for (k = 0; k < n; k++) {
                    if (adj[j][k] != 0) {
                        indegree[k]--;
                    }
                }
                break;     
                 }}}
}
int main() {
    createGraph();
    topoSort();
    return 0;
}