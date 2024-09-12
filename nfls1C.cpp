#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
string s, a, b;
struct node { char c; int p; } nds[N];
bool tong[N];

bool cmp(node x, node y) {
	if (x.c == y.c) return x.p > y.p;
	return x.c < y.c;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		nds[i].c = s[i]; nds[i].p = i;
	}
	sort(nds, nds + n, cmp);
	int i = s.length() - 1, t = 0;
	for (int j = 1; j <= n / 2; ++j) {
		while (tong[i]) --i;
		b += s[i];
		tong[i] = true;
		while (nds[t].p >= i || tong[nds[t].p]) ++t;
		a += nds[t].c;
		tong[nds[t].p] = true;
	}
	
	if (a < b) cout << "DA\n";
	else cout << "NE\n";
	cout << a;
	return 0;
}
