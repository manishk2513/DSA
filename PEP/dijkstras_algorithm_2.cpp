#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct Edge{
	int v;
	int wt;

	Edge(int v, int wt): v(v), wt(wt) {}
};

void dijkstra(int src, vector<vector<Edge>> &g, int v){
	vector<int> dist(v, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});

	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if(d > dist[u]) continue;

		for(Edge e : g[u]){
			if(dist[e.v] > dist[u] + e.wt){
				dist[e.v] = dist[u] + e.wt;
				pq.push({dist[e.v], e.v});
			}
		}
	}
	cout<<endl<<"shortest distance from node "<<src<<" : \n";
	for(int i = 0; i < v; i++){
		cout<<"Node: "<<i<<" -> ";
		if(dist[i] == INT_MAX){
			cout<<"INFINITY(unreachable)\n";
		} else {
			cout<<dist[i]<<endl;
		}
	}
}

int main(){
	int V = 6;
	vector<vector<Edge>> g(V);

	g[0].push_back(Edge(2, 2));
	g[0].push_back(Edge(1, 4));
	g[1].push_back(Edge(1, 1));
	g[1].push_back(Edge(5, 9));
	g[1].push_back(Edge(4, 6));
	g[3].push_back(Edge(3, 3));
	g[3].push_back(Edge(4, 1));
	g[4].push_back(Edge(5, 2));

	dijkstra(0, g, V);
	return 0;
}