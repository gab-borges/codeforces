#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define N 3123
int n, m, k;
vector<int> adj[N];
set<iii> proibidos;
set<ii> visitados;
map<ii, ii> parent;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        proibidos.insert({a, b, c});
    }

    queue<ii> q;

    q.push(ii(0, 1));
    visitados.insert({0, 1});
    ii destino = {-1, -1};

    while(!q.empty()) {
        auto [prev, curr] = q.front(); q.pop();

        if (curr == n) {
            destino = {prev, curr};
            break;
        }

        for (auto nxt : adj[curr]) {
            if (!visitados.count(ii(curr, nxt)) && !proibidos.count(iii(prev, curr, nxt))) {
                visitados.insert(ii(curr, nxt));
                parent[ii(curr, nxt)] = {prev, curr};
                q.push(ii(curr, nxt));
            }
        }
    }

    if (destino == ii({-1, -1})) {
        cout << -1 << '\n';
        return 0;
    }
    
    vi ans;
    ii atual = destino;
    while (atual.second != 1) {
        ans.push_back(atual.second);
        atual = parent[atual];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    cout << ans.size() - 1 << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
