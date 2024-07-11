#include <bits/stdc++.h>
using namespace std;

int dfs (vector<vector<int>>& graph, int node, vector<bool>& visited) {
	visited[node] = true;

	for (int neighbor : graph[node])
		if (!visited[neighbor])
			return dfs (graph, neighbor, visited);

	return node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> graph(n+1);

	for (int i=1; i<=n; i++) {
		int a;
		cin >> a;
		graph[i].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		vector<bool> visited(n+1, false);

		cout << graph[dfs(graph, i, visited)][0] << " ";
	}

	cout << "\n";

	return 0;
}
