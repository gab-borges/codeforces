#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl; for(auto &row:a){for(auto &x:row) cout<<x<<' '; cout << endl;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    int s0, s1, s2;
    if ('0' <= s[0] && s[0] <= '9')
        s0 = s[0] - '0';
    else
        s0 = s[0] - 'A' + 10;

    if ('0' <= s[1] && s[1] <= '9')
        s1 = s[1] - '0';
    else
        s1 = s[1] - 'A' + 10;

    if ('0' <= s[2] && s[2] <= '9')
        s2 = s[2] - '0';
    else
        s2 = s[2] - 'A' + 10;

    double a = 0.5 * (s2 - 2*s1 + s0);
    double b = s1 - s0 - a;
    double c = s0;

    double yv = -1*(b*b - 4*a*c) / (4*a);

    printf("%.15f\n", yv);

    return 0;
}
