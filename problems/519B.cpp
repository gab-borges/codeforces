#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ll n;
    cin >> n;
 
    ll *A = new ll[n];
    ll *B = new ll[n-1];
    ll *C = new ll[n-2];

    ll i;
    for(i=0; i<n; i++)
        cin >> A[i];
 
    for(i=0; i<n-1; i++)
        cin >> B[i];
 
    for(i=0; i<n-2; i++)
        cin >> C[i];
 
    sort(A, A+n);
    sort(B, B+n-1);
    sort(C, C+n-2);
 
    int found = 0;
    for(i=0; i<n-1 && !found; i++)
        if(A[i] != B[i]) {
            found = 1;
            cout << A[i] << "\n";
        }
    if(!found)
        cout << A[n-1] << "\n";
    
    found = 0;
    for(i=0; i<n-2 && !found; i++)
        if(B[i] != C[i]) {
            found = 1;
            cout << B[i] << "\n";
        }
    if(!found)
        cout << B[n-2] << "\n";
    
    return 0;
}