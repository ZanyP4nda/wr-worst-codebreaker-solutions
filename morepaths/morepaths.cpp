#include <bits/stdc++.h>

using namespace std;

#define INF std::numeric_limits<int>::max()

struct edge {
	bool longest = false; // bool if edge was part of longest path
	int node;
	int weight;

	// default constructor
	edge() {
		node = 0;
		weight = 0;
	}

	edge(int n, int w) {
		node = n;
		weight = w;
	}
};

vector<int> A; // set to store unique distances from top left to bottom right
vector<vector<edge>> adjDijkstra; // adjacency list for dijkstra longest (bottom right to top left)
vector<vector<edge>> adjBfs; // adjacency list for bfs (top left to bottom right)
vector<int> dist; // longest distances between node and last node
vector<pair<int, int>> longestEdge; // longest edge connected to node i (as a form of indices in adjDijkstra yuckyyuckyyucky)

/* TO DO : =========================

Test if traversing from bottom right to top left will allow visiting each node only once

note: this will mean dist will store longest distance from node to first node

========================= */

// find the longest paths from each node to end node
int dijkstra_longest(int s, int n) {
	priority_queue<pair<int, int>> q;
	q.push({s, n - 1}); // visit the end node with weight

	dist.resize(n);
	dist[n - 1] = s; // set dist to last node as s
	for(int i = 0; i < n - 1; ++i) dist[i] = -INF; // set all other values in dist to negative infinity

	longestEdge.resize(n);

	while(!q.empty()) {
		int a = q.top().second; q.pop(); // curr node

		for(int i = 0; i < adjDijkstra[a].size(); ++i) {
			int b = adjDijkstra[a][i].node;
			int w = adjDijkstra[a][i].weight;

			if(dist[a] + w > dist[b]) {
				dist[b] = dist[a] + w;
				q.push({dist[b], b});

				longestEdge[b] = make_pair(a, i);
			}
		}
	}

	for(int i = 0; i < dist.size(); ++i) {
		cout << i << ".\t" << dist[i] << "\t" << "\n";
	}

	for(auto e : longestEdge) {
		cout << adjDijkstra[e.first][e.second] << "\n";
	}

	//print adjacency list
	int numNode = 0;
	for(auto node : adjDijkstra) {
		cout << "==== " << numNode << " ====" << "\n";
		for(auto edge : node) {
			cout << edge.node << " " << edge.weight << " " << edge.longest << "\n";
		}
		++numNode;
	}

	A.push_back(dist[0]);
	return dist[0];
}

void bfs_permutate(int s, int n, int k) {
	cout << "====== BFS =====" << "\n";
	// queue to store next node to visit
	// add nodes in same depth first, then children
	queue<pair<edge, int>> q; // store edge to traverse and distance from start node to parent node
	q.push({edge(0, s), 0}); // visit first node first

	while(!q.empty()) {
		int a = q.front().first.node;
		int w = q.front().first.weight;
		int d = q.front().second; // distance from start node to curr node
		q.pop();

		int newPath = d + dist[a]; // distance of new path created
		//cout << a << " " << d << " " << newPath << "\n";
		A.push_back(newPath);

		// add child nodes to queue
		for(edge e : adjBfs[a]) {
			q.push(make_pair(e, d + w));
		}
	}
	cout << "====== END BFS =====" << "\n";
}

int main() {
	int n, m , k;
	cin >> n >> m >> k;

	vector<vector<int>> grid;
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

	// construct adjacency list for dijkstra longest
	// connect nodes left and up instead of right and down
	// this allows traversal from bottom right to top left
	// dist will store longest distance from node to last node instead of first node
	adjDijkstra.resize(n * m);

	// construct adjacency list for BFS
	// connect nodes right and up
	// traverse from top left to bottom right
	adjBfs.resize(n * m);

	int currRow, currCol = 0;
	for(int i = 0; i < n * m; ++i) {
		if(currCol > 0) {
			int left = grid[currRow][currCol - 1];
			int leftNode = i - 1;
			adjDijkstra[i].push_back(edge(leftNode, left));
		}

		if(currRow > 0) {
			int up = grid[currRow - 1][currCol];
			int upNode = i - m;
			adjDijkstra[i].push_back(edge(upNode, up));
		}

		if(currCol < m - 1) {
			int right = grid[currRow][currCol + 1];
			int rightNode = i + 1;
			adjBfs[i].push_back(edge(rightNode, right));
		}

		if(currRow < n - 1) {
			int down = grid[currRow + 1][currCol];
			int downNode = i + m;
			adjBfs[i].push_back(edge(downNode, down));
		}

		++currCol;
		if(currCol >= m) {
			currCol = 0;
			++currRow;
		}
	}

//	//print adjacency list
//	int numNode = 0;
//	for(auto node : adjDijkstra) {
//		cout << "==== " << numNode << " ====" << "\n";
//		for(auto edge : node) {
//			cout << edge.node << " " << edge.weight << "\n";
//		}
//		++numNode;
//	}

//	//print adjacency list (BFS)
//	int numNode = 0;
//	for(auto node : adjBfs) {
//		cout << "==== " << numNode << " ====" << "\n";
//		for(auto edge : node) {
//			cout << edge.node << " " << edge.weight << "\n";
//		}
//		++numNode;
//	}

	dijkstra_longest(grid[n - 1][m - 1], n * m);
//	bfs_permutate(grid[0][0], n * m, k);
//	sort(A.begin(), A.end());
//	for(int a : A) {
//		cout << a << " ";
//	}
//	cout << "\n";
//
//	cout << *(A.begin()) << "\n";
	return 0;
}
