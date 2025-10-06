#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << char('a'+x) << ' '; cout << '\n';
#define vvdebug(a) cout << #a <<" ="<<endl;int cnt=0;for(auto &row:a){cout << char('a'+cnt++) << ": "; for(auto &x:row) cout<<char(x+'a')<<' '; cout << endl;}

int n;
vector<string> s;
vector<int> adj[26];
vector<bool> visited(26, false), inStack(26, false);
vi toporder;
set<int> letras;

bool dfs(int node) {
    visited[node] = true;
    inStack[node] = true;

    for (int nei : adj[node]) {
        if (!visited[nei]) {
            if(dfs(nei)) return true;
        }
        else if (inStack[nei]) {
            return true;
        }
    }

    toporder.push_back(node);
    inStack[node] = false;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    s.assign(n, "");
    for (auto &i : s) cin >> i;

    for (int i = 1; i < n; i++) {
        if (s[i-1].starts_with(s[i])) {
            cout << "Impossible\n";
            return 0;
        }

        int menorTamanho = min(s[i].size(), s[i-1].size());
        for (int j = 0; j < menorTamanho; j++) {
            if (s[i][j] != s[i-1][j]) {
                adj[s[i-1][j]-'a'].push_back(s[i][j]-'a');
                letras.insert(s[i-1][j]-'a');
                letras.insert(s[i][j]-'a');
                break;
            }
        }
    }

    for (auto i : letras) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    reverse(toporder.begin(), toporder.end());

    for (int i = 0; i < 26; i++)
        letras.insert(i);
    for (auto i : toporder)
        letras.erase(i);

    for (auto i : toporder)
        cout << char(i+'a');
    for (auto i : letras)
        cout << char(i+'a');
    
    cout << '\n';

    return 0;
}
