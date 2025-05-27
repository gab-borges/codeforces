#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int good=0, bad=0;
        int good_zeros = 0, good_ones = 0;
        for (int i = 0; i < n/2; i++) {
            if (s[i] == s[n-i-1]) {
                good++;
                if (s[i] == '0')
                    good_zeros++;
                else
                    good_ones++;
            }
            else {
                bad++;
            }
        }

        if (good == k) {
            cout << "YES\n";
            continue;
        }

        if (good < k) {
            if ((k-good) % 2 == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        int ok = 0;
        if (good > k) {
            if ((good-k) % 2 == 0) {
                int goal = (good-k)/2;
                if (good_zeros >= goal && good_ones >= goal)
                    ok = 1;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
