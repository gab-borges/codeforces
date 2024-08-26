#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, n;
	cin >> n >> x;

	vector<int> A(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];


	sort (A.begin(), A.end());


	int count = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		count += A[i];

		if (count <= x) ans++;

		else break;
	}

	cout << ans << '\n';

	return 0;
}

