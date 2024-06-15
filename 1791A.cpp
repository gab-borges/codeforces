#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    for(int k=0; k<t; k++) {
        char c;
        cin >> c;
        string s = "codeforces";
 
        int res=0;
        for(int i=0; i<s.size(); i++)
            if(s[i]==c) {
                res = 1;
                break;
            }
 
        if(res)
            cout << "YES\n";
        else
            cout <<"NO\n";
    }
 
    return 0;
}