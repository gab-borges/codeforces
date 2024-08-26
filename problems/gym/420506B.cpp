#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<int>> v(m+1);

	for (int i = 0; i < n; i++)
		v[0].push_back(i);

	while (q--) {
		char c; int a, b;
		cin >> c >> a >> b;

		if (c == 's') {
			v[b].push_back(v[a].back());
			v[a].pop_back();
		}

		else {
			if (b >= v[a].size())
				cout << -1 << '\n';

			else
				cout << v[a][b] << '\n';
		}
	}

	return 0;
}

