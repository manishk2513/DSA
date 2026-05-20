#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

    void bfsTraversal(int start) const {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex.\n";
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
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
        cout << '\n';
    }

    vector<int> shortestPath(int source, int destination) const {
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[source] = true;
        q.push(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) {
                break;
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        vector<int> path;
        if (!visited[destination]) {
            return path;
        }

        for (int cur = destination; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    bool isConnected() const {
        if (vertices == 0) {
            return true;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;
        int visitedCount = 0;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return visitedCount == vertices;
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
    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    g.bfsTraversal(start);

    int source, destination;
    cout << "Enter source and destination for shortest path: ";
    cin >> source >> destination;

    vector<int> path = g.shortestPath(source, destination);
    if (path.empty()) {
        cout << "No path exists between " << source << " and " << destination << ".\n";
    } else {
        cout << "Shortest path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << '\n';
    }

    if (g.isConnected()) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }

    return 0;
}
