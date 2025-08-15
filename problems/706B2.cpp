#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;

	vi x(n);
	for (int i = 0; i < n; i++) cin >> x[i];

	int q; cin >> q;
	
	vi m(q);
	for (int i = 0; i < q; i++) cin >> m[i];

	sort(x.begin(), x.end());

	for (int i = 0; i < q; i++) {
		auto ans = upper_bound(x.begin(), x.end(), m[i]);
		cout << ans - x.begin() << '\n';
	}

	return 0;
}
