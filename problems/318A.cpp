#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, k;
	cin >> n >> k;

	if (n % 2 == 0) {
		if (k > n/2) {
			cout << 2 * (k - n/2) << '\n';
		}

		else {
			cout << 2*k - 1 << '\n';
		}
	}

	else {
		if (k <= n/2 + 1) {
			cout << 2*k -1 << '\n';
		}

		else {
			cout << 2 * (k - n/2 - 1) << '\n';
		}
	}

	return 0;
}
