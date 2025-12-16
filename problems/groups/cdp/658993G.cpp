#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define N 2123

int n, m;
vector<vector<char>> A(N, vector<char>(N));
vector<vi> grupos;
vector<bool> linhas(N, false), colunas(N, false);

void agrupa(int i, int j, int grupo) {
    if (A[i][j] == '.') return;
    if (grupos[i][j] != 0) return;

    grupos[i][j] = grupo;

    if (!linhas[i]) {
        linhas[i] = true;
        for (int k = 0; k < m; k++) {
            agrupa(i, k, grupo);
        }
    }
    
    if (!colunas[j]) {
        colunas[j] = true;
        for (int k = 0; k < n; k++) {
            agrupa(k, j, grupo);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    grupos.assign(n, vi(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int grupo = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '*' && grupos[i][j] == 0)
                agrupa(i, j, grupo++);
        }
    }

    ll ans = 0;
    vector<ll> conta_grupos(N*N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll grupo = grupos[i][j];
            if (grupo == 0) continue;
            conta_grupos[grupo]++;
            ans = max(ans, conta_grupos[grupo]);
        }
    }

    cout << ans << '\n';

    return 0;
}
