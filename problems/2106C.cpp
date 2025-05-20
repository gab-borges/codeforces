#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second)
        return true;

    if (a.second < b.second)
        return false;
    
    if (a.first >= b.first)
        return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ii> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i].first;
        for (int i = 0; i < n; i++)
            cin >> A[i].second;
        
        sort(A.begin(), A.end(), cmp);

        int acabou = 0;

        if (A[0].second != -1) {
            ll soma = A[0].first + A[0].second;
            for (int i = 1; i < n; i++) {
                if (A[i].second != -1) {
                    if (soma != A[i].first + A[i].second) {
                        cout << 0 << '\n';
                        acabou = 1;
                    }
                }
                else {
                    break;
                }
            }
        }

        else {

        }
    }

    return 0;
}
