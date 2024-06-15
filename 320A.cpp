#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    string s = to_string(n);
    
    for(ll i=0; i<s.size(); i++) {
        if(s[i]=='1') {
            if(i<s.size()-2 && s[i+1]=='4' && s[i+2]=='4') {
                s.erase(s.begin()+i+2);
                s.erase(s.begin()+i+1);
                s.erase(s.begin()+i);
            }
            else if(i<s.size()- 1 && s[i+1]=='4') {
                s.erase(s.begin()+i+1);
                s.erase(s.begin()+i);
            }
            else {
                s.erase(s.begin()+i);
            }
            i--;
        }
    }
    
    if(s.size()!=0)
        cout << "NO" << "\n";
    else
        cout << "YES" << "\n";
    
    return 0;
}