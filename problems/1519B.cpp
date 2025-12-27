#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vi> dp(102, vi(102));
    for (int i = 0; i < 102; i++) {
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for (int i = 1; i < 102; i++) {
        for (int j = 1; j < 102; j++) {
            dp[i][j] = dp[i][j-1] + i+1;
        }
    }

    int t; cin >> t;

    while(t--) {
        cin >> n >> m >> k;
        dp[n-1][m-1] == k ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
