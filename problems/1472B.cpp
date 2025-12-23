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

    while (t--) {
        int n; cin >> n;
        int cnt1=0, cnt2=0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;

            if (x == 1) cnt1++;
            else cnt2++;
        }

        ll total = cnt1 + cnt2*2;

        if (total % 2 == 1)
            cout << "NO\n";
        else if (cnt2 % 2 == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
