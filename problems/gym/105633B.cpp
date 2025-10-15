#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
ll a, b;
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    
    ans = a;
    int ans_uns = __builtin_popcountll(a);

    ll atual = a;

    while (1) {
        ll candidato = atual + (atual & -atual);

        if (candidato > b || candidato < atual)
            break;
        
        int uns_candidato = __builtin_popcountll(candidato);

        if (uns_candidato < ans_uns) {
            ans_uns = uns_candidato;
            ans = candidato;
        }

        if (atual == b) break;

        atual = candidato;
    }

    cout << ans << '\n';

    return 0;
}