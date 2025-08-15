#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define N 312345

vi adj[N];
vector<bool> visited(N, false);
int n, m;

void dfs(int node) {
	if (visited[node]) return;
	if (node == n) return;

	visited[node] = true;

	for (auto nei : adj[node])
		if (!visited[nei])
			dfs(nei);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(n-1);

	for (int i = 1; i <= n; i++) {
		if (visited[i]) cout << "B";
		else cout << "A";
	}

	cout << '\n';

	return 0;
}
