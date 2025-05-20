#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int n, m, p, s;
int t;
vi subset;
set<int> uset;
vector<ii> pairs;
ll c = 0;

void search(int k) {
    if (k == t) {
        for (int i = 1; i <= p; i++) {
            for (int j = p + 1; j <= p + s; j++) {
                uset.insert(i);
                uset.insert(j);
                int ok = 1;
                for (auto i : pairs) {
                    if (uset.count(i.first) && uset.count(i.second)) {
                        ok = 0;
                        break;
                    }
                }
                
                if (ok) c++;
                uset.erase(i);
                uset.erase(j);
            }
        }
    }
    else {
        search(k+1);
        subset.push_back(k);
        uset.insert(k);
        search(k+1);
        uset.erase(subset[subset.size()-1]);
        subset.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p >> s;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        pairs.push_back({a, b});
    }

    // p+s+1 até n
    t = n + 1;
    search(p+s+1);

    cout << c << '\n';

    return 0;
}
