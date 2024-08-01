#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int cont = 0;

		cont += n/4 + (n%4)/2;

		cout << cont << '\n';
	}

	return 0;
}
