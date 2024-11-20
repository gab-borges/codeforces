#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {
		int k; cin >> k;

		vi A(k+5, 0);
		for (int i = 0; i < k; i++) {
			int x; cin >> x; A[x]++;
		}

		k-=2;

		for (int i = 0; i < A.size(); i++) {
			if (A[i] > 0) {
				A[i]--;

				if (k%i==0 && A[k/i]>0) {
					cout << i << " " << k/i << '\n';
					break;
				}

				A[i]++;
			}
		}
	}

	return 0;
}

