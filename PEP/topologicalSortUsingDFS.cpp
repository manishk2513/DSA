#include<iostream>
#include<vector>
#include<stack>
using namespace std;

	// 				[[1], [2], [], [2, 4], []]
	// 				[ 1,   0,  0,     0,   0 ]
	// 				[0th, ]

void findTopoSort(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st){
	visited[node] = 1;
	for(int it : adj[node]){
		if(!visited[it]){
			findTopoSort(it, visited, adj, st);
		}
	}
	st.push(node);
}

vector<int> topoSort(vector<vector<int>> &adj){
	int n = adj.size();
	stack<int> st;
	vector<int> visited(n, 0);

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			findTopoSort(i, visited, adj, st);
		}
	}

	vector<int> topo;

	while(!st.empty()){
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}

int main(){

	int v = 5;
	vector<vector<int>> adj = {
		{1}, {2}, {}, {2, 4}, {}
	};

	vector<int> ans = topoSort(adj);

	for(int i : ans){
		cout<<i<<" ";
	}

	return 0;
}