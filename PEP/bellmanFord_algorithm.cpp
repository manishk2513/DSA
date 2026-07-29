#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// using a flat edge list
struct Edge{
	int u;
	int v;
	int wt;

	Edge(int u, int v, int wt): u(u), v(v), wt(wt) {}
};

void bellmanFord(int src, vector<Edge> &g, int v){
	vector<long long> dist(v, LLONG_MAX);
	dist[src] = 0;

	for(int i = 0; i < v - 1; i++){
		for(Edge &e : g){
			if(dist[e.u] != LLONG_MAX && dist[e.u] + e.wt < dist[e.v]){
				dist[e.v] = dist[e.u] + e.wt;
			}
		}
	}
	for(Edge &e : g){
		if(dist[e.u] != LLONG_MAX && dist[e.u] + e.wt < dist[e.v]){
			cout<<"Negative cycle distance"<<endl;
			return;
		}
	}
	cout<<"\nShortest distance from node "<<src<<" : \n";
	for(int i = 0; i < v; i++){
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
	vector<Edge> g;

	g.push_back(Edge(0, 1, -1));
	g.push_back(Edge(0, 2, 4));
	g.push_back(Edge(1, 2, 3));
	g.push_back(Edge(1, 3, 2));
	g.push_back(Edge(1, 4, 2));
	g.push_back(Edge(3, 2, 5));
	g.push_back(Edge(3, 1, 1));
	g.push_back(Edge(4, 3, -3));

	bellmanFord(0, g, V);
	return 0;
}