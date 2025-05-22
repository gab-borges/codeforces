#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n; string s;
        cin >> n >> s;
        
        vi ans(n, 0);
        vi nxt(26, n);
        
        ans[n-1] = 1;
        nxt[s[n-1] - 'a'] = n-1;
        
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i+1] + nxt[s[i] - 'a'] - i;
            nxt[s[i] - 'a'] = i;
        }
        
        cout << ans[0] << '\n';
    }

    return 0;
}
