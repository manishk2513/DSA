#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    bool directed;
    vector<vector<int>> adj;

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

    void display() const {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j];
                if (j < adj[i].size() - 1) {
                    cout << " -> ";
                }
            }
            cout << " -> NULL\n";
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

    g.display();

    return 0;
}
