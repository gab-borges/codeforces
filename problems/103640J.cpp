#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long ll;

int w, h;

bool cmpDireita(iii& A, iii&B) {
	auto [xA, yA, corA] = A;
	auto [xB, yB, corB] = B;
	return yA > yB;
}

bool cmpEsquerda(iii& A, iii& B) {
	auto [xA, yA, corA] = A;
	auto [xB, yB, corB] = B;
	return xA > xB;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> w >> h;

	int n;
	cin >> n;

	vector<iii> esquerda, direita, cima, baixo;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		iii obj1 = {x1, y1, i};
		iii obj2 = {x2, y2, i};

		int ok1=0, ok2=0;
		if (x1==0 || x1==w || y1==0 || y1==h) ok1=1;
		if (x2==0 || x2==w || y2==0 || y2==h) ok2=1;

		if (!(ok1 && ok2)) continue;

		if (x1 == 0) esquerda.push_back(obj1);
		else if (x1 == w) direita.push_back(obj1);
		else if (y1 == 0) baixo.push_back(obj1);
		else if (y1 == h) cima.push_back(obj1);

		if (x2 == 0) esquerda.push_back(obj2);
		else if (x2 == w) direita.push_back(obj2);
		else if (y2 == 0) baixo.push_back(obj2);
		else if (y2 == h) cima.push_back(obj2);
	}

	sort(esquerda.begin(), esquerda.end());
	sort(cima.begin(), cima.end());
	sort(direita.begin(), direita.end(), cmpDireita);
	sort(baixo.begin(), baixo.end(), cmpEsquerda);

	vector<iii> total;
	total.reserve(esquerda.size() + direita.size() + baixo.size() + cima.size());
	total.insert(total.end(), esquerda.begin(), esquerda.end());
	total.insert(total.end(), cima.begin(), cima.end());
	total.insert(total.end(), direita.begin(), direita.end());
	total.insert(total.end(), baixo.begin(), baixo.end());

	stack<int> s;

	for (auto i : total) {
		int seg = get<2>(i);

		if (!s.empty() && s.top() == seg) s.pop();
		else s.push(seg);
	}

	if (s.empty()) cout << "Y\n";
	else cout << "N\n";

	return 0;
}
