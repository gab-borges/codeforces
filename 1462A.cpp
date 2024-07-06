#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	for (int k=0; k<t; k++) {
		int n;
		cin >> n;

		vector<int> v;

		for (int i=0; i<n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		int f=0, g=n-1;
		int i=0;
		vector<int> r;
		while (f <= g) {
			if(i%2==0) {
				r.push_back(v[f++]);	
			}
			else {
				r.push_back(v[g--]);
			}

			i++;
		}

		for(auto j : r)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}
