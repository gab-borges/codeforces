#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

const int N = 212345;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> dp(N);

    auto s = [](int i) {
        ll sum = 0;
        do { sum += i%10; } while (i/=10);
        return sum;
    };

    for (int i = 1; i < N; i++) {
        dp[i] = dp[i-1] + s(i);
    }

    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
