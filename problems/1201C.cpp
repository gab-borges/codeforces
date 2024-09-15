#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define N 212345

int n, k;
int A[N];

ll f(int x) {
	ll c = 0;

	for (int i = n/2; i < n; i++)
		if (A[i] < x)
			c += (x - A[i]);
	
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	sort(A, A+n);

	int lo = A[n/2], hi = INT_MAX;

	while (lo < hi) {
		int m = lo + (hi - lo + 1) / 2;

		if (f(m) > k) hi = m - 1;
		else lo = m;
	}

	cout << lo << '\n';

	return 0;
}

