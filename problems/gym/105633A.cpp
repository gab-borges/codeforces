#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl;int cnt=0;for(auto &row:a){cout << char('a'+cnt++) << ": "; for(auto &x:row) cout<<char(x+'a')<<' '; cout << endl;}
int n;
vi A;

void diminui_em_cada(int inicio) {
    int menor = INT_MAX;
    for (int i = inicio; i < n; i++) {
        if (A[i] == 0) break;
        menor = min(menor, A[i]);
    }
    for (int i = inicio; i < n; i++) {
        if (A[i] == 0) break;
        A[i] -= menor;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    A.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ok = 1;
    ll ans = 0;

    while (ok) {
        ok = 0;

        int grupos = 0;
        vi comp;

        // conta os "componentes"
        if (A[0]>0) { grupos++; comp.push_back(0); }
        if (A[0]) ok = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != 0 && A[i-1]==0) {
                grupos++;
                comp.push_back(i);
            }

            if (A[i] != 0) ok = 1;
        }
        
        ans += grupos;
        
        for (auto i : comp)
            diminui_em_cada(i);
    }

    cout << ans << '\n';

    return 0;
}
