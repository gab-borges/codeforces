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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vi dp(n+1, INT_MIN);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int p = INT_MIN;

        if (i - a >= 0) p = max(p, dp[i-a] + 1);
        if (i - b >= 0) p = max(p, dp[i-b] + 1);
        if (i - c >= 0) p = max(p, dp[i-c] + 1);

        dp[i] = p;
    }

    cout << dp[n] << '\n';

    return 0;
}
