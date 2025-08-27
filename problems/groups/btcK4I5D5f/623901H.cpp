#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define N 212345

vi A(N);
vector<ii> arestas;
vi vizinhosDiferentes(N, 0);
vi vizinhosIguais(N, 0);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	for (int i = 0; i < n - 1; i++) {
		 int a, b; cin >> a >> b;
		 arestas.push_back({a, b});

		 if (A[a] == A[b]) {
			  vizinhosIguais[a]++;
			  vizinhosIguais[b]++;
		 }
		 else {
			  vizinhosDiferentes[a]++;
			  vizinhosDiferentes[b]++;
		 }
	}

	vector<ii> saldo(n+1);

	for (int i = 1; i <= n; i++) {
		saldo[i].first = vizinhosIguais[i] - vizinhosDiferentes[i];
		saldo[i].second = i;
	}

	sort(saldo.begin(), saldo.end());

	if (saldo[n].first > 0) {
		A[saldo[n].second] = !A[saldo[n].second];
	}
	
	ll numArestas=0;
	for (auto par : arestas) {
		int a = par.first, b = par.second;
		if (A[a] == A[b]) numArestas++;
	}

	cout << n - numArestas << '\n';

	return 0;
}
