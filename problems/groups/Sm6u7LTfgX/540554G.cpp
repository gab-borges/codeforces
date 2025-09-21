#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

struct Trie {
	struct Node {
		 unordered_map<char, int> next;
		 bool end;
		 Node() {
			 end = false;
		 }
	};

	vector<Node> t;

	Trie() { t.emplace_back(); }

	void insert(string s) {
		 int u = 0;
		 for (char c : s) {
			if (t[u].next.find(c) == t[u].next.end()) {
				t[u].next[c] = t.size();
				t.emplace_back();
			}
			u = t[u].next[c];
		 }
		 t[u].end = true;
	}

	string search(string s) {
		int u = 0, i = 0;
		int lastMoreThanOne = -1;

		for (char c : s) {
			 if (t[u].next.find(c) == t[u].next.end())
				 return "";

			 u = t[u].next[c];
			 
			 if (t[u].next.size() > 1) lastMoreThanOne = i;
			 
			 i++;
		}
		
		string ans;
		if (lastMoreThanOne == -1) ans = s.substr(0,1); 
		else ans = s.substr(0, (lastMoreThanOne+1)+1);

		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<string> strings(n);
	Trie trie;

	for (int i = 0; i < n; i++) {
		cin >> strings[i];
		trie.insert(strings[i]);
	}

	for (int i = 0; i < n; i++) {
		string ans = trie.search(strings[i]);
		cout << ans << '\n';
	}	

	return 0;
}
