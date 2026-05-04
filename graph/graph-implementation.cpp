#include<iostream>
#include<vector>
using namespace std;

int main(){
	int nodes;
	cout<<"enter no of nodes: ";
	cin>>nodes;

	vector<vector<int>> adj (nodes, vector<int>(nodes, 0));

	int Edges;
	cout<<"enter no of Edges: ";
	cin>>Edges;

	int s, d, w;
	cout<<"enter the pairs (source, destination) and weight:"<<endl;

	int i;

	for(i = 0; i < Edges; i++){
		cin>>s>>d>>w;
		adj[s][d] = w;
		adj[d][s] = w;
	}

	int j = 0;

	for(i = 0; i < nodes; i++){
		for(j = 0; j < nodes; j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

return 0;

}