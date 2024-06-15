#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    for(int k=0; k<t; k++) {
        string s;
        cin >> s;
        ll n = s.size();

        map <ll, char> imap;
        stack <ll> upper, lower;

        for(ll i=0; i<n; i++) {
            if(s[i]=='B') {
                if(!upper.empty()) {
                    imap[upper.top()] = '$';
                    upper.pop();
                }
            }

            else if(s[i]=='b') {
                if(!lower.empty()) {
                    imap[lower.top()] = '$';
                    lower.pop();
                }
            }
 
            else {
                imap[i] = s[i];
 
                if(isupper(s[i]))
                    upper.push(i);
 
                else
                    lower.push(i);
            }
        }
 
        for(ll i=0; i<n; i++)
            if(imap.count(i) && imap[i]!='$')
                cout << imap[i];
        cout << "\n";
    }
 
    return 0;
}