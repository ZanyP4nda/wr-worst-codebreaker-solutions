#include <bits/stdc++.h>

using namespace std;

#define INF std::numeric_limits<int>::max()

// ------------
// Implentation of Eppstein's algorithm
// -----------

set<int> dijkstraLoopyKthShortest(int n, vector<vector<pair<int, int>>> adj, int k) {
	priority_queue<pair<int, int>> q; // priority queue to store next shortest dist (negative distance to sort by min)
	q.push({0, 0}); // first node to visit is start node

	set<int> P; // set of shortest paths from start to end

	vector<int> count(n); // number of paths found to each node
	for(int i = 0; i < n; ++i) count[i] = 0;

	while(!q.empty() && count[n - 1] < k) {
		int l = q.top().first, a = q.top().second; q.pop();

		// if k paths found to node, no other variations can be found
		if(count[a] == k) {
			continue;
		}

		// increment count to node
		++count[a];

		// if reached end node, add new shortest path found to set
		if(a == n - 1) {
			P.insert(l);
		}

		// Add all adjacent edges to min priority queue
		for(auto node : adj[a]) {
			int b = node.first;
			int w = node.second;
			q.push({l + w, b});
		}
	}

	return P;
}

int main() {
	int numVertices, numEdges, k;
	cin >> numVertices >> numEdges >> k;

	vector<vector<pair<int, int>>> adj(numVertices);
	for(int i = 0; i < numEdges; ++i) {
		int startNode, endNode, w;
		cin >> startNode >> endNode >> w;
		adj[startNode - 1].push_back(make_pair(endNode - 1, w));
		adj[endNode - 1].push_back(make_pair(startNode - 1, w));
	}

	set<int> P = dijkstraLoopyKthShortest(numVertices, adj, k);
	for(int p : P) {
		cout << p << "\n";
	}
	return 0;
}
