#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll t;
	cin >> t;

	while(t--) {
		ll n, k;
		cin >> n >> k;

		ll div = (k-1) / (n-1);

		cout << k + div << '\n';
	}

	return 0;
}
