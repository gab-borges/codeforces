#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

ll n, q, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;

    while (t--) {
        cin >> n >> q;

        while (q--) {
            char c; cin >> c >> c;

            if (c == '>') {
                cin >> x >> y;

                ll w = 1LL << n;
                ll p = w >> 1;
                ll v = 1;

                while (p > 0) {
                    if (x <= p && y <= p) {
                    }
                    else if (x > p && y > p) {
                        x -= p; y -= p;
                        v += p*p;
                    }
                    else if (x > p && y <= p) {
                        x -= p;
                        v += 2*p*p;
                    }
                    else {
                        y -= p;
                        v += 3*p*p;
                    }

                    w = w >> 1;
                    p = w >> 1;
                }

                cout << v << '\n';
            }

            else {
                cin >> x;
                
                ll i = 0, j = 0;
                ll w = 1LL << (2*n - 2);
                ll p = 1LL << (n - 1);
                ll v = 0;
                
                while (w > 0) {
                    if (x <= w + v) {
                    }
                    else if (x <= 2*w + v) {
                        i += p; j += p;
                        v += w;
                    }
                    else if (x <= 3*w + v) {
                        j += p;
                        v += 2*w;
                    }
                    else {
                        i += p;
                        v += 3*w;
                    }

                    w = w >> 2;
                    p = p >> 1;
                }

                cout << j + 1 << " " << i + 1 << '\n';
            }
        }
    }

    return 0;
}
