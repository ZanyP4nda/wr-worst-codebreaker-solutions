#include <bits/stc++.h>

using namespace std;

#define FOR(s, e) for(int i = s; i < e; ++i)

vector<vector<int>> grid;

int yen-dijkstra(int startValue, int n, vector<vector<pair<int, int>>> adj) {
	priority_queue<pair<int, int>> q; // priority queue to store next shortest dist (negative distance to sort by min)
	q.push({0, 0}); // first node to visit is start node

	set<int> P; // set of shortest paths from start to end

	vector<bool> isSpurred(n) = {0}; // bool vector storing if a node has been spurred

	while(!q.empty() && !isSpurred[n - 1]) {
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
	int n, m, k;
	cin >> n >> m >> k;
//	maxDepth = log2(k);
//	kValues.reserve(2 ** maxDepth);
	for(int i = 0; i < n; ++i) {
		vector<int> row;
		for(int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			row.push_back(x);
		}
		grid.push_back(row);
	}
	cout << solve(n - 1, m - 1, 0) << "\n";
	FOR(0, k  - 1) {
		q.pop();
	}
	cout << q.top() << "\n";
	return 0;
