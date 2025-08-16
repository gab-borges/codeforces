#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

vector<string> diasSemana = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
vi proximoDia = {0, 3, 4, 5, 1, 1};
vi duracao = {0, 30, 30, 30, 32, 31};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	ll n; cin >> n;

	unordered_map<string, ll> map;
	for (ll i = 0; i < 7; i++) map[diasSemana[i]] = i;

	ll today = map[s];
	ll ans = LLONG_MAX;
	
	for (ll i = 0; i < n; i++) {
		ll D; cin >> D;

		if (D == 0) {
			ll baseWait = 30;
			ll renewalWeekday = (today + baseWait) % 7;
			if (renewalWeekday == 0) baseWait++;
			else if (renewalWeekday == 6) baseWait += 2;
			ans = min(ans, baseWait);
			continue;
		}

		int diaCriacao = (today - D % 7 + 7 ) % 7;
		
		ll diasPassados = 0;
		int diaAtual = diaCriacao;

		for (int k = 0; k < 5 && diasPassados < D; k++) {
			diasPassados += duracao[diaAtual];
			diaAtual = proximoDia[diaAtual];
		}

		if (diasPassados >= D) {
			ans = min(ans, diasPassados - D);
			continue;
		}

		ll diasRestantes = D - diasPassados;
		ll numCiclos91Dias = diasRestantes / 91;
		diasPassados += numCiclos91Dias * 91;

		while (diasPassados < D) {
			diasPassados += duracao[diaAtual];
			diaAtual = proximoDia[diaAtual];
		}

		ans = min(ans, diasPassados - D);
	}

	cout << ans << '\n';

	return 0;
}
