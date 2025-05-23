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
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        int x=0, y=0;
        int ok = 0;

        set<tuple<int, int, int>> states;

        for (int i = 0; i < 50000; i++) {
            if (x == a && y == b) {
                ok = 1;
                break;
            }

            tuple<int, int, int> current = {x, y, i%n};

            if (states.find(current) != states.end())
                break;

            char move = s[i%n];

            switch (move) {
                case 'N':
                    y++;
                    break;

                case 'S':
                    y--;
                    break;
                
                case 'E':
                    x++;
                    break;
                
                case 'W':
                    x--;
                    break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
