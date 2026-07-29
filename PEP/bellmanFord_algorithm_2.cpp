#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// using an adjacency list
struct Edge{
	int u;
	int v;
	int wt;

	Edge(int u, int v, int wt): u(u), v(v), wt(wt) {}
};

void bellmanFord(int src, vector<vector<Edge>> &g, int V){
	vector<long long> dist(V, LLONG_MAX);
	dist[src] = 0;

	// Relax all edges V-1 times
	for(int i = 0; i < V - 1; i++){
		for(int u = 0; u < V; u++){  // For each vertex
			for(Edge &e : g[u]){     // For each edge from that vertex
				if(dist[e.u] != LLONG_MAX && dist[e.u] + e.wt < dist[e.v]){
					dist[e.v] = dist[e.u] + e.wt;
				}
			}
		}
	}
	
	// Check for negative cycle
	for(int u = 0; u < V; u++){
		for(Edge &e : g[u]){
			if(dist[e.u] != LLONG_MAX && dist[e.u] + e.wt < dist[e.v]){
				cout<<"Negative cycle detected!"<<endl;
				return;
			}
		}
	}
	
	cout<<"\nShortest distance from node "<<src<<" : \n";
	for(int i = 0; i < V; i++){
		cout<<"Node: "<<i<<" -> ";
		if(dist[i] == LLONG_MAX){
			cout<<"INFINITY(unreachable)"<<endl;
		} else {
			cout<<dist[i]<<endl;
		}
	}
}

int main(){
	int V = 6;
	vector<vector<Edge>> g(V);

	g[0].push_back(Edge(0, 1, -1));
	g[0].push_back(Edge(0, 2, 4));
	g[1].push_back(Edge(1, 2, 3));
	g[1].push_back(Edge(1, 3, 2));
	g[1].push_back(Edge(1, 4, 2));
	g[3].push_back(Edge(3, 2, 5));
	g[3].push_back(Edge(3, 1, 1));
	g[4].push_back(Edge(4, 3, -3));

	bellmanFord(0, g, V);
	return 0;
}
