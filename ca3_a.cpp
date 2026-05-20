#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        matrix.assign(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void display() {
        cout << "Here is the Adjacency Matrix:\n";
        cout << "  ";
        for (int i = 0; i < vertices; i++)
            cout << i << " ";
        cout << "\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    bool isConnected(int u, int v) {
        return matrix[u][v] == 1;
    }
};

int main() {
    int v = 4;

    GraphMatrix gm(v);

    gm.addEdge(0, 1);
    gm.addEdge(0, 2);
    gm.addEdge(1, 2);
    gm.addEdge(2, 3);

    gm.display();

    return 0;
}