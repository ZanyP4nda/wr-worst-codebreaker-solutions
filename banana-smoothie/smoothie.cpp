#include <bits/stdc++.h>
using namespace std;

long smoothie(int n, int k, vector<long> b) {
	long total = 0;
	sort(b.begin(), b.end(), greater<long>());
	for(int i = k - 1; i < b.size(); i += k) {
		if(b[i] > 0) {
			total += b[i];
		}
	}
	return total;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<long> b(n);
	for(int i = 0; i < n; ++i) {
		long a;
		cin >> a;
		b[i] = a;
	}
	cout << smoothie(n, k, b) << "\n";;
}
