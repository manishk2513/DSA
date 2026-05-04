#include<iostream>
#include<vector>
using namespace std;

int main(){
	int nodes;
	cout<<"Enter no of nodes: ";
	cin>>nodes;

	vector<int>adj[nodes];

	int u, v, Edges;

	cout<<"enter no of edges: ";
	cin>>Edges;

	int i;

	cout<<"enter all the pairs connected (u, v): "<<endl;

	for(i = 0; i < Edges; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int j;

	for(i = 0; i < nodes; i++){
		cout<<i<<" -> ";

		for(j = 0; j < adj[i].size();j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}