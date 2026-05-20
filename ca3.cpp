#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix {
private:
    int vertices;           // number of nodes
    vector<vector<int>> matrix;  // 2D grid to store edges

public:
    // Constructor: create an empty graph with V vertices
    GraphMatrix(int V) {
        vertices = V;
        // Fill a V x V grid with 0 (no edges at the start)
        matrix.assign(V, vector<int>(V, 0));
    }

    // Add an edge between node u and node v (undirected)
    void addEdge(int u, int v) {
        matrix[u][v] = 1;  // u connects to v
        matrix[v][u] = 1;  // v connects to u (both directions)
    }

    // Print the full matrix
    void display() {
        cout << "\n--- Adjacency Matrix ---\n";

        // Print column headers
        cout << "   ";
        for (int i = 0; i < vertices; i++)
            cout << i << " ";
        cout << "\n";

        // Print each row
        for (int i = 0; i < vertices; i++) {
            cout << i << "| ";
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Check if two nodes are directly connected — O(1)
    bool isConnected(int u, int v) {
        return matrix[u][v] == 1;
    }
};


// class GraphList {
// private:
//     int vertices;
//     vector<vector<int>> adjList;  // each index holds a list of neighbors

// public:
//     // Constructor: create an empty graph with V vertices
//     GraphList(int V) {
//         vertices = V;
//         adjList.resize(V);  // create V empty lists
//     }

//     // Add an edge between node u and node v (undirected)
//     void addEdge(int u, int v) {
//         adjList[u].push_back(v);  // v is a neighbor of u
//         adjList[v].push_back(u);  // u is a neighbor of v
//     }

//     // Print all neighbor lists
//     void display() {
//         cout << "\n--- Adjacency List ---\n";
//         for (int i = 0; i < vertices; i++) {
//             cout << "Node " << i << " -> ";
//             for (int neighbor : adjList[i]) {
//                 cout << neighbor << " ";
//             }
//             cout << "\n";
//         }
//     }

//     // Get all neighbors of a node
//     vector<int> getNeighbors(int u) {
//         return adjList[u];
//     }
// };

int main() {
    int V = 4;  // 4 nodes: 0, 1, 2, 3

    // ---- Test Adjacency Matrix ----
    GraphMatrix gm(V);
    gm.addEdge(0, 1);
    gm.addEdge(0, 2);
    gm.addEdge(1, 2);
    gm.addEdge(2, 3);
    gm.display();

    // Check if nodes are connected
    cout << "\nIs 0 connected to 1? " << (gm.isConnected(0, 1) ? "Yes" : "No") << "\n";
    cout << "Is 0 connected to 3? " << (gm.isConnected(0, 3) ? "Yes" : "No") << "\n";

    // ---- Test Adjacency List ----
    GraphList gl(V);
    gl.addEdge(0, 1);
    gl.addEdge(0, 2);
    gl.addEdge(1, 2);
    gl.addEdge(2, 3);
    gl.display();

    // Print neighbors of node 2
    cout << "\nNeighbors of node 2: ";
    for (int n : gl.getNeighbors(2))
        cout << n << " ";
    cout << "\n";

    return 0;
}