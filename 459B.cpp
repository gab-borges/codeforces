#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
 
    ll *B = new ll[n];
 
    ll min=LLONG_MAX, max=LLONG_MIN;
    ll cmin=0, cmax=0;
 
    for(ll i=0; i<n; i++) {
        cin >> B[i];
 
        if(B[i]>max) {
            max = B[i];
            cmax=1;
        }
 
        else if(B[i]==max)
            cmax++;

        if(B[i] < min) {
            min = B[i];
            cmin=1;
        }
        
        else if(B[i]==min)
            cmin++;
    }
 
    if(max==min)
        cout << 0 << " " << (cmax * (cmax-1))/2 << "\n";
 
    else
        cout << (max-min) << " " << cmax*cmin << "\n";
 
    return 0;
}