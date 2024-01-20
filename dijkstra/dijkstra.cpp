#include <bits/stdc++.h>

using namespace std;

#define INF std::numeric_limits<int>::max()

int dijkstra(int n, int start, int end, vector<vector<pair<int, int>>> adj) {
	priority_queue<pair<int, int>> q; // priority queue to store next shortest dist (negative distance to sort by min)
	q.push({0, start}); // first node to visit is start node

	int dist[n]; // create an integer array of size n
	for(int i = 0; i < n; ++i) dist[i] = INF; // set all values in dist to infinity
	dist[start - 1] = 0; // Set dist to first node (1) as 0

	bool visited[n] = { 0 }; // set all nodes as unvisited

	while(!q.empty()) {
		int a = q.top().second; q.pop();
		if(visited[a - 1]) continue;
		visited[a - 1] = true;
		for(auto node : adj[a - 1]) {
			int b = node.first;
			int w = node.second;
			if(dist[a - 1] + w < dist[b - 1]) {
				dist[b - 1] = dist[a - 1] + w;
				q.push({-dist[b - 1], b});
			}
		}
	}

	return dist[end - 1]; // return shortest distance to end node
}

int main() {
	int numVertices, endVertex;
	cin >> numVertices >> endVertex;

	vector<vector<pair<int, int>>> adj(numVertices);
	for(int i = 0; i < numVertices; ++i) {
		int startNode, endNode, w;
		cin >> startNode >> endNode >> w;
		adj[startNode - 1].push_back(make_pair(endNode, w));
	}

	cout << dijkstra(numVertices, 1, endVertex, adj) << "\n";
	return 0;
}
