#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> c(1);
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		c.push_back(a);
	}

	vector<vector<int>> graph(n+1);
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	long long ans = 0;

	vector<bool> visited(n+1, false);
	
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			queue<int> q;
			q.push(i);

			int min = INT_MAX;

			while(!q.empty()) {
				int curr = q.front();
				q.pop();
				
				if(c[curr] < min)
					min = c[curr];

				for(int k : graph[curr]) {
					if(!visited[k]) {
						visited[k] = true;
						q.push(k);
					}
				}
			}

			ans += min;
		}
	}
			
	cout << ans << "\n";

	return 0;
}
