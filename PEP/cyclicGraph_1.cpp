#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : v(vertices), adj(vertices) {}

    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    bool dfsHasCycle(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsHasCycle(neighbor, node, visited))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfsHasCycle(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1); 
    cout << "Graph 1 cyclic: " << (g1.isCyclic() ? "Yes" : "No") << "\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    cout << "Graph 2 cyclic: " << (g2.isCyclic() ? "Yes" : "No") << "\n";

    return 0;
}