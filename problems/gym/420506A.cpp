#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	unordered_map<ll, ll> map;

	while (q--) {
		char c; ll x;
		cin >> c >> x;

		if (c == 'a') {
			if (map.find(x) == map.end())
				map[x] = 1;
			else
				map[x]++;
		}

		else if (c == 't') {
			if (map.find(x) == map.end())
				map[x] = 0;

			else
				map[x]--;
		}

		else {
			if (map.find(x) == map.end())
				cout << 0 << '\n';
			else
				cout << map[x] << '\n';
		}
	}

	return 0;
}

