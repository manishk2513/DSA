#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int val){
		data = val;
		next = nullptr;
	}
};

class Graph {
	int v;
	Node **head;
public:
	Graph(int vertices){
		v = vertices;
		head = new Node* [v];

		for(int i = 0; i < v; i++){
			head[i] = nullptr;
		}
	}

	void insert(int u, int v){
		Node *newNode = new Node(v);
		newNode->next = head[u];
		head[u] = newNode;
	}

	void insertUndirected(int u, int v){
		insert(u, v);
		insert(v, u);
	}

	void display(){
		for(int i = 0; i < v; i++){
			cout<<i<<" -> ";

			Node *temp = head[i];
			while(temp != nullptr){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	void bfs(int start){
		vector<bool>visited(v, false);
		visited[start] = true;
		queue<int> q;
		q.push(start);

		while(!q.empty()){
			int u = q.front();
			q.pop();
			cout<<u<<" ";

			Node *temp = head[u];

			while(temp != nullptr){
				int neighbor = temp->data;

				if(!visited[neighbor]){
					visited[neighbor] = true;
					q.push(neighbor);
				}
				temp = temp->next;
			}
		}
	}

	void dfsHelper(int start, vector<bool> &visited){
		visited[start] = true;
		cout<<start<<" ";

		Node *temp = head[start];
		while(temp != nullptr){
			int neighbor = temp->data;
			if(!visited[neighbor]){
				dfsHelper(neighbor, visited);
			}
			temp = temp->next;
		}
	}

	void dfs(int start){
		vector<bool> visited(v, false);
		dfsHelper(start, visited);
	}
};

int main(){
	Graph g(5);

	g.insertUndirected(0, 1);
    g.insertUndirected(0, 2);
    g.insertUndirected(1, 2);
    g.insertUndirected(2, 4);
    g.insertUndirected(3, 4);

	g.display();

	cout<<"BFS:- ";
	g.bfs(0);

	cout<<endl<<"DFS:- ";
	g.dfs(0);

	return 0;
}
