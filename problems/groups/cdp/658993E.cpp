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
    
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    ll p; cin >> p;

    for (int i = 0; i < 8; i++) {
        ll x = uniform_int_distribution<ll>(2, p-1)(rng);
        
        cout << "? " << x << " 2\n";
        cout.flush();

        ll a;
        cin >> a;
        if (a == -1) {
            cout << ":(\n";
            return 0;
        }
    }

    cout << ":)\n";

    return 0;
}
