#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// also known as KAHN'S ALGORITHM
// directed graph

vector<int> topoSort(vector<vector<int>> &adj){
	int n = adj.size();
	vector<int> indegree(n, 0);
	queue<int> q;
	vector<int> list;

	for(int i = 0; i < n; i++){
		for(int next : adj[i]){
			indegree[next];
		}
	}

	for(int i = 0; i < n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int top = q.front();
		q.pop();
		list.push_back(top);

		for(int next : adj[top]){
			indegree[next]--;
			if(indegree[next] == 0){
				q.push(next);
			}
		}
	}
	return list;
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