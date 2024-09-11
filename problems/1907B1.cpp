#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		stack<int> big, small;
		set<int> del;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'b') {
				if(!small.empty()) {
					del.insert(small.top());
					small.pop();
				}
			}

			else if (s[i] == 'B') {
				if(!big.empty()) {
					del.insert(big.top());
					big.pop();
				}
			}

			else if ('a' <= s[i] && s[i] <= 'z') {
				small.push(i);
			}

			else if ('A' <= s[i] && s[i] <= 'Z') {
				big.push(i);
			}
		}
		
		for (auto it = del.rbegin(); it != del.rend(); ++it) {
			s[*it] = '-';
		}

		for (int i = 0; i < s.size(); i++)
			if (s[i] != '-' && s[i] != 'b' && s[i] != 'B')
				cout << s[i];
		cout << '\n';
	}

	return 0;
}

