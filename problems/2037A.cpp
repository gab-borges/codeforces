#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vi A(n+1, 0);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			A[x]++;
		}

		ll score = 0;

		for (auto i : A)
			score += i/2;

		cout << score << '\n';
	}

	return 0;
}

