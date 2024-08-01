#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		string a, b;
		cin >> a >> b;

		vector<array<int, 26>> v(n+1);

		for (int i = 0; i < n; i++) {
			v[i + 1] = v[i];

			v[i + 1][a[i] - 'a']++;
			v[i + 1][b[i] - 'a']--; 
		}

		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;

			int count = 0;

			for (int i = 0; i < 26; i++)
				if (v[r][i] - v[l][i] > 0)
					count += v[r][i] - v[l][i];

			cout << count << '\n';
		}
	}

	return 0;
}
