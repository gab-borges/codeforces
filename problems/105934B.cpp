#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;

	vi A(n), C(n-1);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n - 1; i++) cin >> C[i];

	ll ans = LLONG_MIN;
	ll custo = 0;
	ll receita = 0;

	priority_queue<int, vi, greater<int>> melhoresBaus;

	for (int i = 0; i < n; i++) {
		melhoresBaus.push(A[i]);
		receita += A[i];

		if (melhoresBaus.size() > k) {
			receita -= melhoresBaus.top();

			melhoresBaus.pop();
		}

		ans = max(ans, receita - custo);

		if (i < n - 1)
			custo += C[i];
	}

	cout << ans << '\n';

	return 0;
}
