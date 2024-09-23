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
		int n, k;
		cin >> n >> k;
		ll c = 0, wallet = 0;

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;

			if (a >= k) {
				wallet += a;
			}

			else if (a == 0 && wallet > 0) {
				wallet--;
				c++;
			}
		}

		cout << c << '\n';
	}
	

	return 0;
}

