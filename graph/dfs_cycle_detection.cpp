#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    bool directed;
    vector<vector<int>> adj;

    bool dfsDirected(int node, vector<bool>& visited, vector<bool>& recursionStack) const {
        visited[node] = true;
        recursionStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsDirected(neighbor, visited, recursionStack)) {
                    return true;
                }
            } else if (recursionStack[neighbor]) {
                return true;
            }
        }

        recursionStack[node] = false;
        return false;
    }

    bool dfsUndirected(int node, int parent, vector<bool>& visited) const {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsUndirected(neighbor, node, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

public:
    Graph(int v, bool isDirected) : vertices(v), directed(isDirected) {
        adj.resize(vertices);
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid edge: vertex out of range.\n";
            return;
        }

        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void dfsTraversal(int start) const {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex.\n";
            return;
        }

        vector<bool> visited(vertices, false);
        cout << "DFS Traversal: ";
        dfsPrint(start, visited);
        cout << '\n';
    }

    bool hasCycle() const {
        vector<bool> visited(vertices, false);

        if (directed) {
            vector<bool> recursionStack(vertices, false);
            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    if (dfsDirected(i, visited, recursionStack)) {
                        return true;
                    }
                }
            }
        } else {
            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    if (dfsUndirected(i, -1, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    void dfsPrint(int node, vector<bool>& visited) const {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsPrint(neighbor, visited);
            }
        }
    }
};

int main() {
    int vertices, edges;
    char type;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Directed graph? (y/n): ";
    cin >> type;

    Graph g(vertices, type == 'y' || type == 'Y');

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter each edge as: source destination\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;
    g.dfsTraversal(start);

    if (g.hasCycle()) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}
