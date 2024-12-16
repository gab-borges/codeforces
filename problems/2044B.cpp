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
		string a;
		cin >> a;

		string b = "";
		for (int i = a.size()-1; i >= 0; i--) {
			if (a[i] == 'p') b.push_back('q');
			else if (a[i] == 'q') b.push_back('p');
			else b.push_back('w');
		}

		cout << b << '\n';
	}

	return 0;
}

