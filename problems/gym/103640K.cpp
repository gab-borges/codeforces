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

	unordered_set<char> set;
	vector<string> words(n);

	for (int i = 0; i < n; i++) {
		cin >> words[i];
		set.insert(words[i][0]);
	}

	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (auto j : words[i]) {
			if (set.find(j) == 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			cout << "Y\n";
			return 0;
		}
	}

	cout << "N\n";

	return 0;
}
