#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
    int* recStack;
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
    graph->visited = malloc(vertices * sizeof(int));
    graph->recStack = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
        graph->recStack[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
    struct Node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}

bool isCyclicUtil(struct Graph* graph, int v) {
    if (graph->visited[v] == 0) {
        graph->visited[v] = 1;
        graph->recStack[v] = 1;

        struct Node* temp = graph->adjLists[v];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex] && isCyclicUtil(graph, adjVertex))
                return true;
            else if (graph->recStack[adjVertex])
                return true;
            temp = temp->next;
        }
    }
    graph->recStack[v] = 0;
    return false;
}

bool hasCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (isCyclicUtil(graph, i))
            return true;
    }
    return false;
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

    if (hasCycle(graph)) printf("YES\n");
    else printf("NO\n");

    return 0;
}