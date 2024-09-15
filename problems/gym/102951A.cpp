#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;	

	vector<vi> points(n, vi(2));

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		points[i][0] = x;
	}

	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;

		points[i][1] = y;
	}
	
	ll max = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll distX = pow((points[i][0]-points[j][0]), 2);
			ll distY = pow((points[i][1]-points[j][1]), 2);
			ll dist = distX + distY;

			if (dist > max)
				max = dist;
		}
	}

	cout << max << '\n';

	return 0;
}

