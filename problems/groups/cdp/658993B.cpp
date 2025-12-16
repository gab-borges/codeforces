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

    int n, l; cin >> n >> l;

    vi d(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        ans += d[i];
    }

    ll acum = 0;
    for (int i = 0; i < n; i++) {
        if (acum + d[i] > l) {
            acum = 0;
            ans += 24 - l;
        }

        acum += d[i];
    }

    cout << ans << '\n';

    return 0;
}
