#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<string> V(n);

        for (int i = 0; i < n; i++) cin >> V[i];

        ll ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll diff = 0;

                for (int k = 0; k < m; k++) {
                    diff += abs(V[i][k] - V[j][k]);
                }

                ans = min(ans, diff);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
