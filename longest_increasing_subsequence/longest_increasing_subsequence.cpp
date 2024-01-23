#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> arr;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);	
	}

	vector<int> d; // dynamic programming arr
	for(int x : arr) {
		if(d.size() == 0 || x > d.back()) {
			d.push_back(x); // add to back
		}
		else {
			// Replace 
			int lower = lower_bound(d.begin(), d.end(), x) - d.begin();
			d[lower] = x;
		}
	}

	cout << d.size() << "\n";

	return 0;
}
