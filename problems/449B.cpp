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
vi best_train_routes(N, INT_MAX);
set<int> train_routes;
vector<ii> adj_roads[N];
int n, m, k;

void dijkstra(int s) {
    priority_queue<lli, vector<lli>, greater<lli>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [weight, u] = pq.top(); pq.pop();
        if (dist[u] < weight) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        int u, v, x; cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj_roads[u].push_back({v, x});
        adj[v].push_back({u, x});
        adj_roads[v].push_back({u, x});
    }

    for (int i = 0; i < k; i++) {
        int s, y; cin >> s >> y;
        adj[1].push_back({s, y});
        adj[s].push_back({1, y});
        train_routes.insert(s);
        best_train_routes[s] = min(best_train_routes[s], y);
    }

    dijkstra(1);

    ll essential_routes = 0;
    for (auto &s : train_routes) {
        int y_min = best_train_routes[s];
        if (dist[s] < y_min) {
            continue;
        }

        else if (dist[s] == y_min) {
            bool there_is_min_road = false;
            for (auto [r, w] : adj_roads[s]) {
                if (dist[r] + w == dist[s]) {
                    there_is_min_road = true;
                    break;
                }
            }
            if (!there_is_min_road) {
                essential_routes++;
            }
        }
    }

    cout << k - essential_routes << '\n';
    

    return 0;
}
