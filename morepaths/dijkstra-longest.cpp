#include <bits/stdc++.h>

using namespace std;

#define INF std::numeric_limits<int>::max()

int dijkstraLongest(int startValue, int n, vector<vector<pair<int, int>>> adj) {
	priority_queue<pair<int, int>> q; // priority queue to store next shortest dist (negative distance to sort by min)
	q.push({startValue, 0}); // first node to visit is start node

	vector<int> dist(n); // create an integer array of size n
	for(int i = 0; i < n; ++i) dist[i] = -INF; // set all values in dist to negative infinity
	dist[0] = startValue; // Set dist to first node (1) as starting value

	while(!q.empty()) {
		int a = q.top().second; q.pop();
		cout << "### " << a+1 << " ###" << "\n";
		for(auto edge : adj[a]) {
			int b = edge.first;
			int w = edge.second;
			cout << b + 1 << " " << dist[b] << " " << dist[a] + w << "\n";
			if(dist[a] + w > dist[b]) {
				dist[b] = dist[a] + w;
				q.push({dist[b], b});
				cout << "Replace: " << dist[b] << "\n";
			}
		}
		cout << "\n";
	}

	for(int i = 0; i < dist.size(); ++i) {
		cout << i + 1 << ".\t" << dist[i] << "\n";
	}

	return dist[n-1];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	// Fill grid
	vector<vector<int>> grid;
	for(int i = 0; i < n; ++i) {
		vector<int> row;
		for(int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			row.push_back(x);
		}
		grid.push_back(row);
	}

	vector<vector<pair<int, int>>> adj(n * m);
	int currRow, currCol = 0;
	for(int i = 0; i < n * m - 1; ++i) {
		if(currCol < m - 1) {
			int right = grid[currRow][currCol + 1];
			int rightNode = i + 1;
			adj[i].push_back(make_pair(rightNode, right));
		}
		if(currRow < n - 1) {
			int down = grid[currRow + 1][currCol];
			int downNode = i + m;
			adj[i].push_back(make_pair(downNode, down));
		}
		++currCol;
		if(currCol >= m) {
			currCol = 0;
			++currRow;
		}
	}

	cout << dijkstraLongest(grid[0][0], n * m, adj) << "\n";
	return 0;
}
