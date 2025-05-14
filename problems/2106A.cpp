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
        int n; cin >> n;
        string s; cin >> s;
        ll c = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                c++;
            }

            else {
                c += n - 1;
            }
        }

        cout << c << '\n';
    }

    return 0;
}
