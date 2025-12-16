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

    int n, t; cin >> n >> t;

    vi c(n), l(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> l[i];

    vector<ii> tudo;
    for (int i = 0; i < n; i++)
        tudo.push_back({c[i], l[i]});

    sort(tudo.begin(), tudo.end());

    int ultimaRefinaria = -1;
    ll custo_acum = 0, acum = 0;
    for (int i = 0; i < n; i++) {
        if (acum + tudo[i].second >= t) {
            ultimaRefinaria = i;
            break;
        }

        custo_acum += tudo[i].first * tudo[i].second;
        acum += tudo[i].second;
    }

    if (ultimaRefinaria > -1) {
        custo_acum += tudo[ultimaRefinaria].first * (t - acum);
    }

    cout << custo_acum << '\n';

    return 0;
}
