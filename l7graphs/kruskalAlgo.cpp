#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else { parent[rootV] = rootU; rank[rootU]++; }
        }
    }
};

void kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

    DisjointSet ds(V);
    vector<Edge> result;

    for (Edge &edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            result.push_back(edge);
            ds.unite(edge.src, edge.dest);
        }
    }

    for (Edge &edge : result)
        cout << edge.src << " - " << edge.dest << "  Weight: " << edge.weight << endl;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    kruskalMST(5, edges);
    return 0;
}
