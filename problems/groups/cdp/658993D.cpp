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

    int n; cin >> n;
    vi c(n), r(n), l(n);

    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < n; i++)
        l[i] = r[i] - c[i];

    ll ans = 0;
    ll acum = 0;
    for (int i = 0; i < n; i++) {
        if (acum + l[i] < 0) {
            acum = 0;
            continue;
        }
        acum += l[i];
        ans = max(ans, acum);
    }

    cout << ans << '\n';

    return 0;
}
