#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> A(n);
    vector<pair<ll,ll>> pares;
    ll minimoValor = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
        minimoValor = min(minimoValor, A[i]);
    }

    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        pares.push_back({a-1, b-1});
    }

    if (minimoValor > k) {
        cout << 1 << '\n';
        return 0;
    }

    ll ans = 0;
    for (ll b = 0; b < (1 << n); b++) {
        ll ok = 1;

        for (auto i : pares) {
            if ((b & (1 << (i.first))) && (b & (1 << (i.second)))) {
                ok = 0;
                break;
            }
        }

        if (!ok) continue;

        vector<ll> subset;
        ll somaAtual = 0;

        for (ll i = 0; i < n; i++) {
            if (b & (1 << i)) {
                subset.push_back(A[i]);
                somaAtual += A[i];
                if (somaAtual > k) {
                    ok = 0;
                    break;
                }
            }
        }

        if (!ok) continue;

        ans++;
    }

    cout << ans << '\n';

    return 0;
}
