#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n, x;
		cin >> n >> x;

		int count = 0;

		for (int a = 1; a < n; a++) {
			int lim_b = n / a;

			for (int b = 1; b < lim_b; b++)
				count += max(0, min(x-a-b, (n-a*b)/(a+b)));
		}

		cout << count << '\n';
	}

	return 0;
}
