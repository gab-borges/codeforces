#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define N 112345
vector<ii> adj[N];
vector<ll> dist(N, LLONG_MAX);
vi parent(N, -1);
int n, m;

void dijkstra(int s) {
    dist[s] = 0;
    parent[0] = 0;

    priority_queue<lli, vector<lli>, greater<lli>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    if (dist[n] == LLONG_MAX) {
        cout << -1 << '\n';
        return 0;
    }

    vi path;
    int node = n;
    while (node != 1) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    for (auto i : path)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
