#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v) : vertices(v), adj(v) {}

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid edge: vertex out of range.\n";
            return;
        }
        adj[u].push_back(v);
    }

    void topologicalSort() const {
        vector<int> indegree(vertices, 0);
        for (int u = 0; u < vertices; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < vertices; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() != vertices) {
            cout << "Graph is not a DAG. Topological sort not possible.\n";
            return;
        }

        cout << "Topological Order: ";
        for (int i = 0; i < order.size(); i++) {
            cout << order[i];
            if (i < order.size() - 1) {
                cout << " -> ";
            }
        }
        cout << '\n';
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of directed edges: ";
    cin >> edges;

    cout << "Enter each edge as: source destination\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << '\n';
    g.topologicalSort();

    return 0;
}
