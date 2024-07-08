#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> g(n+1);

	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;
		g[i] = a;
	}

	int r = 0;
	for(int i=1; i<=n; i++) {
		if(g[g[g[i]]]==i) {
			r = 1;
			break;
		}
	}
	
	if(r==1)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
