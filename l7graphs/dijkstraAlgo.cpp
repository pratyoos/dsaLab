#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> PII;

void dijkstra(vector<vector<PII>> &graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << i << " \t " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<PII>> graph(V);

    graph[0] = {{1, 10}, {4, 5}};
    graph[1] = {{0, 10}, {2, 1}, {4, 2}};
    graph[2] = {{1, 1}, {3, 4}};
    graph[3] = {{2, 4}, {4, 3}};
    graph[4] = {{0, 5}, {1, 2}, {3, 3}};

    dijkstra(graph, 0);
    return 0;
}