#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vi A(n);

    for (int i = 0; i < n; i++) cin >> A[i];

    int lo = 0, hi = n - 1;
    int ans = INT_MIN;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int minimo = INT_MAX;
        int minimoIdx = mid;

        for (int i = 0; i < n; i++) {
            int val = A[i];
            if (i <= mid && mid - i < k) val += k - (mid - i);

            if (val <= minimo) {
                minimo = val;
                minimoIdx = i;
            }
        }

        ans = max(ans, minimo);

        if (minimoIdx > mid) lo = mid + 1;
        else if (minimoIdx < mid) hi = mid - 1;
        else break;
    }

    cout << ans << '\n';

    return 0;
}
