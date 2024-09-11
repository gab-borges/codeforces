#include <bits/stdc++.h>
using namespace std;

#define N 112345
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> A;

	vector<int> cores;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		A.push_back({a, b});
		cores.push_back(b);
	}

	sort (A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		if (A[i].second != cores[i]) {
			cout << "N\n";
			return 0;
		}
	}

	cout << "Y\n";

	return 0;
}

