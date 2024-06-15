#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, l;
    cin >> n >> l;
    ll *A = new ll[n];
 
    for(ll i=0; i<n; i++)
        cin >> A[i];
 
    sort(A, A+n);
 
    double maior = A[0] - 0;
 
    for(ll i=1; i<n; i++) {
        double dist = (A[i] - A[i-1]) / 2.0;
        if(dist > maior)
            maior = dist;
    }
 
    if(l - A[n-1] > maior)
        maior = l - A[n-1];
 
    cout << fixed << setprecision(10) << maior << "\n";
 
    return 0;
}