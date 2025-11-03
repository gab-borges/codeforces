#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vector<ll> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        
        ll ans = -1;

        for (ll p : primes) {
            bool all_divisible = true;

            for (int i = 0; i < n; i++) {
                if (A[i] % p != 0) {
                    all_divisible = false;
                    break;
                }
            }

            if (!all_divisible) {
                ans = p;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
