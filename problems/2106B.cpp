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
        int n, x; cin >> n >> x;

        if (x == 0) {
            for (int i = 1; i < n; i++)
                cout << i << ' ';
            cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i < x; i++)
            cout << i << ' ';

        for (int i = n - 1; i > x; i--)
            cout << i << ' ';

        if (x == n) {
            cout << '\n';
            continue;
        }

        cout << x << '\n';
    }

    return 0;
}
