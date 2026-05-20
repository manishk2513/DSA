#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> residual;

    bool bfs(int source, int sink, vector<int>& parent) const {
        vector<bool> visited(vertices, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && residual[u][v] > 0) {
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);

                    if (v == sink) {
                        return true;
                    }
                }
            }
        }

        return visited[sink];
    }

public:
    Graph(int v) : vertices(v), residual(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v, int capacity) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices || capacity < 0) {
            cout << "Invalid edge or capacity.\n";
            return;
        }

        residual[u][v] += capacity;
    }

    int fordFulkerson(int source, int sink) {
        if (source < 0 || sink < 0 || source >= vertices || sink >= vertices) {
            cout << "Invalid source or sink.\n";
            return 0;
        }

        int maxFlow = 0;
        vector<int> parent(vertices, -1);

        while (bfs(source, sink, parent)) {
            int pathFlow = INT_MAX;

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, residual[u][v]);
            }

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residual[u][v] -= pathFlow;
                residual[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }
};

int main() {
    int vertices, edges;
    int source, sink;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter each directed edge as: source destination capacity\n";
    for (int i = 0; i < edges; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        g.addEdge(u, v, capacity);
    }

    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter sink vertex: ";
    cin >> sink;

    int maxFlow = g.fordFulkerson(source, sink);
    cout << "Maximum flow from " << source << " to " << sink << " is: " << maxFlow << '\n';

    return 0;
}
