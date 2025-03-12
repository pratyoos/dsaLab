#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    stack<int> stack;

    stack.push(start);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        for (auto i = adj[v].rbegin(); i != adj[v].rend(); ++i) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2);

    return 0;
}