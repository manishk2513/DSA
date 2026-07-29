#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
	visited[v] = true;
	for(int neighbor : adj[v]){
		if(!visited[neighbor]){
			dfs(neighbor, adj, visited, st);
		}
	}
	st.push(v);
}

vector<int> topoSort(int v, vector<vector<int>> &adj){
	vector<bool> visited(v, false);
	stack<int> st;
	for(int i = 0; i < v; i++){
		if(!visited[i]){
			dfs(i, adj, visited, st);
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

	vector<int> ans = topoSort(v, adj);

	for(int i : ans){
		cout<<i<<" ";
	}

	return 0;
}