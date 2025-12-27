#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int n;
vi A(212345);

int solve() {
    for (int i = 1; i < n - 1; i++) {
        if (A[i-1] < 0 || A[i] < 0 || A[i+1] < 0) {
            return 0;
        }
        else if (2*A[i-1] <= A[i]) {
            A[i] -= 2*A[i-1];
            A[i+1] -= A[i-1];
            A[i-1] = 0;
        }
        else {
            return 0;
        }
    }
    
    if (A[n-3] == 0 && A[n-2] == 0 && A[n-1] == 0)
        return 1;
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> A[i];
        solve() ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}