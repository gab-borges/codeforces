#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll l, r; cin >> l >> r;

	ll Xor = l ^ r;

	if (Xor == 0) {
		cout << 0 << '\n';
		return 0;
	}

	ll ans = 1;
	while (ans <= Xor)
		ans *= 2;
	
	cout << ans - 1 << '\n';

	return 0;
}
