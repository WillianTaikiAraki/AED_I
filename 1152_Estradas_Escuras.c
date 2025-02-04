#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int parent;
    int rank;
} DisjointSet;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

void initializeDisjointSet(DisjointSet *sets, int size) {
    for (int i = 0; i < size; i++) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
}

int findRoot(DisjointSet *sets, int element) {
    if (sets[element].parent != element) {
        sets[element].parent = findRoot(sets, sets[element].parent);
    }
    return sets[element].parent;
}

int areInSameSet(DisjointSet *sets, int element1, int element2) {
    return findRoot(sets, element1) == findRoot(sets, element2);
}

void unionSets(DisjointSet *sets, int element1, int element2) {
    int root1 = findRoot(sets, element1);
    int root2 = findRoot(sets, element2);

    if (root1 != root2) {
        if (sets[root1].rank > sets[root2].rank) {
            sets[root2].parent = root1;
        } else {
            sets[root1].parent = root2;
            if (sets[root1].rank == sets[root2].rank) {
                sets[root2].rank++;
            }
        }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int calculateMinimumSpanningTree(Edge *edges, int vertexCount, int edgeCount) {
    int totalWeight = 0;
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    DisjointSet *sets = (DisjointSet*)malloc(vertexCount * sizeof(DisjointSet));
    initializeDisjointSet(sets, vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        Edge currentEdge = edges[i];
        if (!areInSameSet(sets, currentEdge.source, currentEdge.destination)) {
            totalWeight += currentEdge.weight;
            unionSets(sets, currentEdge.source, currentEdge.destination);
        }
    }

    free(sets);
    return totalWeight;
}

int main() {
    int vertexCount, edgeCount;
    Edge *edges;

    while (scanf("%d %d", &vertexCount, &edgeCount) != EOF) {
        if (vertexCount == 0 && edgeCount == 0) {
            break;
        }

        edges = (Edge*)malloc(edgeCount * sizeof(Edge));

        int totalWeight = 0;
        for (int i = 0; i < edgeCount; i++) {
            int source, destination, weight;
            scanf("%d %d %d", &source, &destination, &weight);
            edges[i].source = source;
            edges[i].destination = destination;
            edges[i].weight = weight;
            totalWeight += weight;
        }

        int mstWeight = calculateMinimumSpanningTree(edges, vertexCount, edgeCount);
        printf("%d\n", totalWeight - mstWeight);

        free(edges);
    }

    return 0;
}
