#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x1,y1,z1,r1;
	int x2,y2,z2,r2;

	cin >> x1 >> y1 >> z1 >> r1;
	cin >> x2 >> y2 >> z2 >> r2;

	if (sqrt(pow(x1-x2, 2) + pow(y1-y2, 2) + pow(z1-z2, 2)) <= r1+r2)
		cout << "S\n";

	else
		cout << "N\n";

	return 0;
}
