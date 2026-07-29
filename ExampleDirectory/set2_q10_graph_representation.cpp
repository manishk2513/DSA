// Q10: Implement a graph using an adjacency list/array and display the graph representation.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes;
    cout << "Enter number of nodes: ";
    if (!(cin >> nodes) || nodes <= 0)
        return 0;

    // store data for each node (integer data)
    vector<int> nodeData(nodes);
    for (int i = 0; i < nodes; ++i)
    {
        cout << "Enter data for node " << i << ": ";
        cin >> nodeData[i];
    }

    // weighted adjacency matrix
    vector<vector<int>> adj(nodes, vector<int>(nodes, 0));

    int Edges;
    cout << "Enter number of edges: ";
    cin >> Edges;

    cout << "Enter edges as: source destination weight (0-based indices)" << endl;
    for (int i = 0; i < Edges; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        if (s >= 0 && s < nodes && d >= 0 && d < nodes)
        {
            adj[s][d] = w;
            adj[d][s] = w; // undirected
        }
        else
        {
            cout << "Invalid edge (" << s << "," << d << "). Ignored.\n";
            i--; // allow re-entry if desired
        }
    }

    cout << "\nNode data:\n";
    for (int i = 0; i < nodes; ++i)
    {
        cout << i << ": " << nodeData[i] << '\n';
    }

    cout << "\nWeighted Adjacency Matrix:\n";
    for (int i = 0; i < nodes; ++i)
    {
        for (int j = 0; j < nodes; ++j)
        {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}