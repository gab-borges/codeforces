#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> x;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		x.push_back(a);
	}

	int q;
	cin >> q;

	int *m = new int[q];
	for(int i=0; i<q; i++)
		cin >> m[i];

	sort(x.begin(), x.end());

	for(int i=0; i<q; i++)
		cout << upper_bound(x.begin(), x.end(), m[i]) - x.begin() << "\n";

	return 0;
}
