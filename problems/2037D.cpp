#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

bool cmp(ii a, ii b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m, L;
		cin >> n >> m >> L;
		int ok = 1;

		vii H, P;

		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			H.push_back({a, b});
		}

		H.push_back({L, L});

		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			P.push_back({a, b});
		}

		priority_queue<int> powers;
		auto i = P.begin();
		ll power = 1;
		int k = 0;

		for (auto it : H) {
			ll dist = it.second - it.first + 2;

			while ((i != P.end()) && (i->first < it.first)) {
				powers.push(i->second);
				++i;
			}

			while ((power < dist) && (powers.size() > 0)) {
				power += powers.top();
				powers.pop();
				k++;
			}

			if ((powers.size() <= 0) && (power < dist)) {
				cout << -1 << '\n';
				ok = 0;
				break;
			}
		}
		
		if (ok)
			cout << k << '\n';
	}

	return 0;
}

