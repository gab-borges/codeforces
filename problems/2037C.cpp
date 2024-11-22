#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		if (n < 5) {
			cout << -1 << '\n';
			continue;
		}

		cout << "1 3 ";

		for (int i = 7; i <= n; i += 2)
			cout << i << " ";

		cout << "5 4 2 ";
		for (int i = 6; i <= n; i += 2)
			cout << i << " ";
		cout << '\n';
	}

	return 0;
}

