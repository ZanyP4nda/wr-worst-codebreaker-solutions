#include <bits/stdc++.h>

using namespace std;

#define FOR(s, e) for(int i = s; i < e; ++i)

vector<vector<int>> grid;
int maxDepth;
vector<int> kValues;

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

int solve(int y, int x, int depth) {
	// cout << y << " " << x << "\n";
	if(y < 0 || x < 0) {
		return NULL;
	}

	int up = solve(y - 1, x, depth + 1);
	int left = solve(y, x - 1, depth + 1);

	if(depth < maxDepth) {
	}

	return max_custom(up, left) + grid[y][x];

	//return max_custom(solveBelowK(y - 1, x), solveBelowK(y, x - 1)) + grid[y][x];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	maxDepth = log2(k);
	kValues.reserve(2 ** maxDepth);
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
