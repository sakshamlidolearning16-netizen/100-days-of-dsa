#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* inDegree;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->inDegree = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
    struct Node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
    graph->inDegree[d]++;
}

void kahnsAlgorithm(struct Graph* graph) {
    int n = graph->numVertices;
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (graph->inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int result[n];

    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            graph->inDegree[v]--;
            if (graph->inDegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("Cycle detected, topological sort not possible\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    kahnsAlgorithm(graph);

    return 0;
}