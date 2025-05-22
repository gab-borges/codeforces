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
        int n, m; cin >> n >> m;
        int ok = 0;
        
        queue<int> q;
        q.push(n);

        while (q.size() > 0) {
            int front = q.front();

            if (front == m) {
                ok = 1;
                break;
            }
            
            if (front % 3 == 0) {
                q.push(front/3.0);
                q.push(2.0*front/3.0);
            }

            q.pop();
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
