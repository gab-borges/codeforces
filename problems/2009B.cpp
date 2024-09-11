#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vi A(n);

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			
			for (int j = 0; j < 4; j++) {
				if (s[j] == '#') {
					A[i] = j + 1;
					break;
				}
			}
		}

		reverse(A.begin(), A.end());

		for (int i : A)
			cout << i << " ";

		cout << '\n';
	}

	return 0;
}

