#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<ii> coords(n);
	vector<ll> dist(n-1);

	int a, b; cin >> a >> b;
	coords[0] = {a, b};

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		coords[i] = {a, b};

		if (a == coords[i-1].first) {
			dist[i-1] = llabs(b - coords[i-1].second);
		}
		else {
			dist[i-1] = llabs(a - coords[i-1].first);
		}
	}

	ll min_upper_bound = dist[0] - 1, max_lower_bound = 1;
	
	ll c = dist[0];
	for (int i = 1; i < n-1; i++) {
		c = dist[i] - c;

		if ((i+1) % 2 == 0)
			max_lower_bound = max(max_lower_bound, 1-c);
		else
			min_upper_bound = min(min_upper_bound, c-1);
	}

	if (max_lower_bound <= min_upper_bound)
		cout << min_upper_bound << '\n';
	else
		cout << -1 << '\n';


	return 0;
}
