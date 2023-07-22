#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct edge {
    int u, v, w;
} edge;

edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

int find(int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void union_(int u, int v) {
    int parent_u = find(u);
    int parent_v = find(v);
    parent[parent_u] = parent_v;
}

int compare_edges(const void *a, const void *b) {
    edge *edge_a = (edge *) a;
    edge *edge_b = (edge *) b;
    return edge_a->w - edge_b->w;
}

void kruskal(edge *edges, int n_edges, int n_vertices) {
    int min_cost = 0;
    for (int i = 0; i < n_vertices; i++) {
        parent[i] = i;
    }
    qsort(edges, n_edges, sizeof(edge), compare_edges);
    for (int i = 0; i < n_edges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u) != find(v)) {
            union_(u, v);
            min_cost += w;
            printf("(%d, %d) -> %d\n", u, v, w);
        }
    }
    printf("Minimum cost of the spanning tree = %d\n", min_cost);
}

int main() {
    int n_vertices, n_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &n_edges);
    printf("Enter the edges (u, v, w):\n");
    for (int i = 0; i < n_edges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    kruskal(edges, n_edges, n_vertices);
    return 0;
}