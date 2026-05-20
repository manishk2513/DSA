#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> reach;

public:
    Graph(int v) : vertices(v), reach(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid edge: vertex out of range.\n";
            return;
        }
        reach[u][v] = 1;
    }

    void warshallTransitiveClosure() {
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (reach[i][j] || (reach[i][k] && reach[k][j])) {
                        reach[i][j] = 1;
                    }
                }
            }
        }
    }

    void displayMatrix() const {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << reach[i][j] << " ";
            }
            cout << '\n';
        }
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

    cout << "\nTransitive Closure (Before Warshall):\n";
    g.displayMatrix();

    g.warshallTransitiveClosure();

    cout << "\nTransitive Closure (After Warshall):\n";
    g.displayMatrix();

    return 0;
}
