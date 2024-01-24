#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<pair<int>> intersection; // stores intersections where up and left have the same value

int solve(int y, int x, int k) {
	if(y < 0 or x < 0) {
		return 0;
	}
	if(k > 0) {
		return min(solve(y - 1, x, k - 1), solve(y, x - 1, k - 1)) + grid[y][x];
	} 
	return max(solve(y - 1, x, k), solve(y, x - 1, k)) + grid[y][x];
}

int main() {
	int n, m , k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) {
		vector<int> row;
		for(int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			row.push_back(x);
		}
		grid.push_back(row);
	}
	cout << solve(n - 1, m - 1, k - 1) << "\n";
	return 0;
}
