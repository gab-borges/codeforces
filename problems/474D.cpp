#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

#define N 112345
const ll MOD = 1'000'000'007;
int t, k, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> k;

    vector<ll> dp(N);
    for (int i = 0; i < k; i++) dp[i] = 1;

    for (int i = k; i < N; i++) {
        dp[i] = (dp[i-1] + dp[i-k]) % MOD;
    }

    vi A(N);
    A[0] = dp[0];
    for (int i = 1; i < N; i++)
        A[i] = (A[i-1] + dp[i]) % MOD;
    
    while(t--) {
        cin >> a >> b;
        cout << (A[b] - A[a-1] + MOD) % MOD << '\n';
    }

    return 0;
}
