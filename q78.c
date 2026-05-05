#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc((vertices + 1) * sizeof(struct Node*));
    for (int i = 0; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int s, int d, int w) {
    struct Node* newNode = createNode(d, w);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    newNode = createNode(s, w);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int key[n + 1];
    bool mstSet[n + 1];
    for (int i = 0; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 1; v <= n; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break;

        mstSet[u] = true;
        totalWeight += key[u];

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            if (mstSet[v] == false && temp->weight < key[v]) {
                key[v] = temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}