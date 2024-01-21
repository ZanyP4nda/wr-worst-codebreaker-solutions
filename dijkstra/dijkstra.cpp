#include <bits/stdc++.h>

using namespace std;

#define INF std::numeric_limits<int>::max()

int dijkstra(int n, vector<vector<pair<int, int>>> adj) {
	priority_queue<pair<int, int>> q; // priority queue to store next shortest dist (negative distance to sort by min)
	q.push({0, 1}); // first node to visit is start node

	vector<int> dist(n); // create an integer array of size n
	for(int i = 0; i < n; ++i) dist[i] = INF; // set all values in dist to infinity
	dist[0] = 0; // Set dist to first node (1) as 0

	vector<bool> visited(n); // set all nodes as unvisited

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

	if(visited[n - 1]) {
		return dist[n - 1]; // return shortest distance to end node
	}

	return -1; // return -1 if impossible
}

int main() {
	int numVertices, numEdges;
	cin >> numVertices >> numEdges;

	vector<vector<pair<int, int>>> adj(numVertices);
	for(int i = 0; i < numEdges; ++i) {
		int startNode, endNode, w;
		cin >> startNode >> endNode >> w;
		adj[startNode - 1].push_back(make_pair(endNode, w));
		adj[endNode - 1].push_back(make_pair(startNode, w));
	}

	cout << dijkstra(numVertices, adj) << "\n";
	return 0;
}
