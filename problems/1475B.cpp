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

    int t; cin >> t;

    vi dp(1123456);
    dp[2020] = 1;
    dp[2021] = 1;

    for (int i = 2022; i < 1123456; i++) dp[i] = dp[i-2020] || dp[i-2021];

    while(t--) {
        int n; cin >> n;

        dp[n] ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
