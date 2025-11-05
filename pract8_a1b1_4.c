#include <stdio.h>
#include <stdbool.h>

#define MAX 20

bool isSafe(int v, int graph[MAX][MAX], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoringUtil(int graph[MAX][MAX], int m, int color[], int v, int V) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;

            color[v] = 0; 
        }
    }
    return false;
}

bool graphColoring(int graph[MAX][MAX], int m, int V) {
    int color[MAX] = {0};

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution exists:\nAssigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i + 1, color[i]);
    return true;
}

int main() {
    int t;
    printf("Enter number of graphs to test: ");
    scanf("%d", &t);

    for (int test = 1; test <= t; test++) {
        int V, m;
        int graph[MAX][MAX];

        printf("\n--- Graph %d ---\n", test);
        printf("Enter number of vertices: ");
        scanf("%d", &V);

        printf("Enter adjacency matrix (%d x %d):\n", V, V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                scanf("%d", &graph[i][j]);
            }
        }

        printf("Enter number of colors available: ");
        scanf("%d", &m);

        printf("\nResult for Graph %d:\n", test);
        graphColoring(graph, m, V);
    }

    return 0;
}