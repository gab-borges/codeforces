#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, k; cin >> n >> k;

	vi h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	ll minSum = 0;
	ll sum = 0;
	for (int i = 0; i < k; i++) sum += h[i];
	minSum = sum;
	int minSumIdx = 0;

	for (int i = k; i < n; i++) {
		sum += h[i] - h[i-k];

		if (sum < minSum) {
			minSum = sum;
			minSumIdx = i-k+1;
		}
	}

	cout << minSumIdx+1 << '\n';

	return 0;
}
