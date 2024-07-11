#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t;
  cin >> t;
 
  for(int k=0; k<t; k++) {
    int n;
    cin >> n;
 
    int *a = new int[n];
 
    for(int i=0; i<n; i++)
      cin >> a[i];
 
    sort(a, a+n);
    int res = 1;
    
    for(int i=0; i<n-1; i++)
      if(abs(a[i] - a[i+1]) > 1) {
        res = 0;
        break;
      }
 
    if(res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
 
  return 0;
}