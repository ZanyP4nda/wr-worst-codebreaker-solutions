#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<pair<int, int>>> adj;

int yens(int s, vector<vector<pair<int, int>>> adj) {
	priority_queue<pair<int, int>> q;
	q.push({0, s}); // visit the first node with starting weight
	return 0;
}

int main() {
	int n, m , k;
	cin >> n >> m >> k;

	// create grid
	for(int i = 0; i < n; ++i) {
		vector<int> row;
		for(int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			row.push_back(x);

		}
		grid.push_back(row);
	}

	// construct adjacency list
	adj.resize(n * m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= m; ++j) {
			if(j > 0) {
				adj[i * m + j - 1].push_back(make_pair(i * m + j, grid[i][j]));
			}

			if(i > 0) {
				adj[(i - 1) * m + j].push_back(make_pair(i * m + j, grid[i][j]));
			}
		}
	}

//	print adjacency list
//	int numNode = 0;
//	for(auto node : adj) {
//		for(auto edge : node) {
//			cout << numNode << " " << edge.first << " " << edge.second << "\n";
//		}
//		++numNode;
//	}

	//cout << solve(n - 1, m - 1, k - 1) << "\n";
	return 0;
}