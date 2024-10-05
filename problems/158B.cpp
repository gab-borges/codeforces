#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vi A(n);

	vi groups(5, 0);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		groups[A[i]]++;
	}

	ll ans = groups[4];
 
 	// Joining the groups with 3 friends and groups with 1 friend
 	ans += groups[3];

	if (groups[1] >= groups[3])
		groups[1] -= groups[3];

	else
		groups[1] = 0;
	

	// Joining the groups of 2 in pairs, and then making any
	// remanescents with 1 only to join.
	ans += groups[2] / 2;

	if (groups[2] % 2) {
		ans++;

		groups[1] = max(0, groups[1] - 2);
	}

	// Joining the groups of 1 in groups of 4
	ans += groups[1] / 4;
	
	if (groups[1] % 4)
		ans++;


	cout << ans << '\n';

	return 0;
}

