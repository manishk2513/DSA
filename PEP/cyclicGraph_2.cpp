#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Graph {
    int v;
    Node** head; 

public:
    Graph(int vertices) {
        v = vertices;
        head = new Node*[v];
        for (int i = 0; i < v; i++)
            head[i] = nullptr;
    }

    ~Graph() {
        for (int i = 0; i < v; i++) {
            Node* curr = head[i];
            while (curr) {
                Node* tmp = curr;
                curr = curr->next;
                delete tmp;
            }
        }
        delete[] head;
    }

    // Insert directed edge u → w
    void insert(int u, int w) {
        Node* newNode = new Node(w);
        newNode->next = head[u];
        head[u] = newNode;
    }

    void addEdge(int u, int w) {
        insert(u, w);
        insert(w, u);
    }

    void display() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            Node* temp = head[i];
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }


    bool dfsHasCycle(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        Node* temp = head[node];       
        while (temp != nullptr) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                if (dfsHasCycle(neighbor, node, visited))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }

            temp = temp->next;
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfsHasCycle(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "Graph 1 (with cycle):\n";
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1); 
    g1.display();
    cout << "Cyclic: " << (g1.isCyclic() ? "Yes" : "No") << "\n\n";

    cout << "Graph 2 (no cycle):\n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.display();
    cout << "Cyclic: " << (g2.isCyclic() ? "Yes" : "No") << "\n\n";

    cout << "Graph 3 (disconnected, one part has cycle):\n";
    Graph g3(6);
    g3.addEdge(0, 1);   
    g3.addEdge(2, 3);   
    g3.addEdge(3, 4);
    g3.addEdge(4, 2);   
    g3.display();
    cout << "Cyclic: " << (g3.isCyclic() ? "Yes" : "No") << "\n";

    return 0;
}