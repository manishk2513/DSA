#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    bool directed;
    vector<vector<int>> matrix;

public:
    Graph(int v, bool isDirected) : vertices(v), directed(isDirected) {
        matrix.assign(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid edge: vertex out of range.\n";
            return;
        }

        matrix[u][v] = 1;
        if (!directed) {
            matrix[v][u] = 1;
        }
    }

    bool edgeExists(int u, int v) const {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            return false;
        }
        return matrix[u][v] == 1;
    }

    void display() const {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << '\n';
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

    int u, v;
    cout << "\nCheck if an edge exists. Enter source and destination: ";
    cin >> u >> v;

    if (g.edgeExists(u, v)) {
        cout << "Edge exists between " << u << " and " << v << ".\n";
    } else {
        cout << "Edge does not exist between " << u << " and " << v << ".\n";
    }

    return 0;
}
