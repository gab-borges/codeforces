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
        int n; cin >> n;

        vi A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<ll> dp(n+1, LLONG_MAX);

        for (int i = 0; i < n; i++) {
            if (dp[A[i]] == 1) continue;

            dp[A[i]] = 1;

            if (A[i] == 1) continue;

            for (int j = 2; j <= n/A[i]; j++) {
                if (dp[j] != LLONG_MAX) {
                    ll c = dp[j];
                    for (ll k = j; k <= n; k*=A[i]) {
                        dp[k] = min(dp[k], c);
                        c++;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] == LLONG_MAX)
                cout << -1 << ' ';
            else
                cout << dp[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
