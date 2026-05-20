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
        adj[v].push_back(u);
    }

    int countConnectedComponents() const {
        vector<bool> visited(vertices, false);
        int components = 0;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                components++;
                bfsComponent(i, visited);
            }
        }

        return components;
    }

    void printConnectedComponents() const {
        vector<bool> visited(vertices, false);
        int componentId = 1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                cout << "Component " << componentId << ": ";
                bfsPrintComponent(i, visited);
                cout << '\n';
                componentId++;
            }
        }
    }

private:
    void bfsComponent(int start, vector<bool>& visited) const {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void bfsPrintComponent(int start, vector<bool>& visited) const {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter each undirected edge as: source destination\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << '\n';
    g.printConnectedComponents();

    int total = g.countConnectedComponents();
    cout << "Total connected components: " << total << '\n';

    return 0;
}
