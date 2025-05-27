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
        string s;
        cin >> s;

        int sum = (s[3]-'0') + 10*(s[2]-'0') + 100*(s[1]-'0') + 1000*(s[0]-'0');
        int raiz = sqrt(sum);

        if (sum == raiz * raiz)
            cout << 0 << " " << raiz << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
