#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int ans = 0, max = 0;

		for (int x = 2; x <= n; x++) {
			int sum = 0;
				
			int k = 1;
			while (k*x <= n) {
				sum += k*x;
				k++;
			}	

			if (sum > max) {
				ans = x;
				max = sum;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
