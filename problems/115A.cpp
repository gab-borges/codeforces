#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> g(n+1);

	for(int i=1; i<=n; i++)
		cin >> g[i];
	
	int max = 0;
	for(int i=1; i<=n; i++) {
		int num = g[i];
		int count = 1;

		while (num != -1) {
			num = g[num];
			count++;
		}

		if(count>max)
			max = count;
	}

	cout << max << "\n";

	return 0;
}
