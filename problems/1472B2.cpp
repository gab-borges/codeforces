#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        vi A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        ll total = 0;
        for (int valor : A) total += valor;

        if (total % 2 != 0) {
            cout << "NO\n"; continue;
        }

        ll alvo = total / 2;

        vector<bool> dp(total+2);

        dp[0] = true;
        for (int peso : A) {
            for (int s = alvo; s >= peso; s--) {
                if (dp[s-peso])
                    dp[s] = dp[s-peso];
            }
        }

        dp[alvo] ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
