#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int p=0; p<t; p++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> graph(n+1);

		for(int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		/* Algorithm idea:
		 * Find a node that has only 1 connection: border.
		 * Go to the only node connected to it: semicentral.
		 * The number of connections of semicentral is y-1
		 *
		 * Go to the only node connected to it that doesn't have
		 * 1 connection: central.
		 * The number of connections of central is x
		 */

		int border;

		for(int i=1; i<=n; i++) {
			if(graph[i].size() == 1) {
				border = i;
				break;
			}
		}

		int semicentral = graph[border][0];

		int y = graph[semicentral].size() - 1;

		int central;

		for(int i=0; i<graph[semicentral].size(); i++) {
			if(graph[graph[semicentral][i]].size() > 1) {
				central = graph[semicentral][i];
				break;
			}	
		}

		int x = graph[central].size();

		cout << x << " " << y << "\n";
	}

	return 0;
}
