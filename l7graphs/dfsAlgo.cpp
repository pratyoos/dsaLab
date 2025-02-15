#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsIterative(int start, vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
        }

        for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
            if (!visited[*it])
                s.push(*it);
        }
    }
}

int main() {
    int V = 6;
    vector<vector<int>> graph(V);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1, 5};
    graph[5] = {2, 4};

    cout << "DFS Traversal (Iterative): ";
    dfsIterative(0, graph);

    return 0;
}