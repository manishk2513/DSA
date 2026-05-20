#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> weight;

public:
    Graph(int v) : vertices(v), weight(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices || w <= 0) {
            cout << "Invalid edge or weight.\n";
            return;
        }

        weight[u][v] = w;
        weight[v][u] = w;
    }

    void primMST() const {
        vector<int> key(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        vector<bool> inMST(vertices, false);

        key[0] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = -1;
            int minKey = INT_MAX;

            for (int i = 0; i < vertices; i++) {
                if (!inMST[i] && key[i] < minKey) {
                    minKey = key[i];
                    u = i;
                }
            }

            if (u == -1) {
                cout << "Graph is disconnected; MST cannot be formed for all vertices.\n";
                return;
            }

            inMST[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (weight[u][v] != 0 && !inMST[v] && weight[u][v] < key[v]) {
                    key[v] = weight[u][v];
                    parent[v] = u;
                }
            }
        }

        int totalWeight = 0;
        cout << "Edges in Minimum Spanning Tree (Prim's):\n";
        for (int i = 1; i < vertices; i++) {
            if (parent[i] == -1) {
                cout << "Graph is disconnected; MST cannot be formed for all vertices.\n";
                return;
            }
            cout << parent[i] << " - " << i << "  weight: " << weight[i][parent[i]] << '\n';
            totalWeight += weight[i][parent[i]];
        }

        cout << "Total MST weight: " << totalWeight << '\n';
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter each weighted edge as: source destination weight\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    cout << '\n';
    g.primMST();

    return 0;
}
