#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

int min_custom(int a, int b) {
	if(a < 0 && b < 0) {
		return 0;
	}
	if(a < 0 && b >= 0 || a > b) {
		return b;
	}
//	if(b < 0 && a >= 0 || a < b) {
//		return a;
//	}
	return a;
}

int max_custom(int a, int b) {
	if(a < 0 && b < 0) {
		return 0;
	}
	if(a < 0 && b >= 0 || b > a) {
		return b;
	}
//	if(b < 0 && a >= 0 || a > b) {
//		return a;
//	}
	return a;
}

int solve(int y, int x, int k) {
	// cout << y << " " << x << "\n";
	if(y < 0 || x < 0) {
		return -1;
	}
	if(k > 0) {
		cout << "k: " << k << " (" << grid[y][x] << ")\n";
		return min_custom(solve(y - 1, x, k - 1), solve(y, x - 1, k - 1)) + grid[y][x];
	} 
	return max_custom(solve(y - 1, x, k - 1), solve(y, x - 1, k - 1)) + grid[y][x];
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