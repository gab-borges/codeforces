#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll k, x;

ll f(ll w) {
	if (w <= k)
		return ((1 + w) * w) / 2;

	return ((1 + k) * k) / 2 + ((3*k - w - 1) * (w - k)) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> k >> x;

		if (k * k <= x) {
			cout << 2*k - 1 << '\n';
			continue;
		}

		ll l = 1, r = 2*k - 1;

		while (l < r) {
			ll m = l + (r - l + 1) / 2;

			if (f(m) > x) r = m - 1;

			else l = m;
		}

		if (f(l) == x) cout << l << '\n';
		else if (f(l) < x) cout << l + 1 << '\n';
		else cout << l - 1 << '\n';
	}

	return 0;
}

