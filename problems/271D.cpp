#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int P1 = 31, M1 = 1e9 + 9;
int P2 = 37, M2 = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    string b; cin >> b;
    int k; cin >> k;
    int n = s.size();

    set<pair<ll, ll>> hashes;

    for (int i = 0; i < n; i++) {
        int bads = 0;
        ll hash1 = 0, hash2 = 0;

        for (int j = i; j < n; j++) {
            if (!(b[s[j]-'a']-'0')) bads++;

            if (bads > k) break;

            hash1 = (hash1 * P1 + (s[j]-'a'+1)) % M1;
            hash2 = (hash2 * P2 + (s[j]-'a'+1)) % M2;

            hashes.insert({ hash1, hash2 });
        }
    }

    cout << hashes.size() << '\n';

    return 0;
}
