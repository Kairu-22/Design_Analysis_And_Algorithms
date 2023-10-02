#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph, FILE* outputFile) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    int* parent = (int*)malloc(V * sizeof(int));
    for (i = 0; i < V; i++)
        parent[i] = -1;

    i = 0;
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edge[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }

    fprintf(outputFile, "Edges in Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        fprintf(outputFile, "%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(parent);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the total number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges in the format (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt for writing.\n");
        return 1;
    }

    kruskalMST(graph, outputFile);
    fclose(outputFile);

    printf("Output saved to output.txt\n");

    return 0;
}
