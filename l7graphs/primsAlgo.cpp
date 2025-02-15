#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 5

int minKey(int key[], bool inMST[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << "\n";
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    bool inMST[V] = {false};

    fill(key, key + V, INT_MAX);
    key[0] = 0, parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(key, inMST);
        inMST[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}