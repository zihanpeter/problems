#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e3 + 5;

int n;
struct node {
	string s;
	int a, b, c, d;
} nds[N];

bool cmp(node x, node y) {
	return x.s < y.s;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> nds[i].s >> nds[i].a >> nds[i].b >> nds[i].c;
		nds[i].d = nds[i].a + nds[i].b + nds[i].c;
	}
	sort(nds + 1, nds + n + 1, cmp);
	for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) 
		if (abs(nds[i].a - nds[j].a) <= 5 && abs(nds[i].b - nds[j].b) <= 5 
			&& abs(nds[i].c - nds[j].c) <= 5 && abs(nds[i].d - nds[j].d) <= 10) 
			cout << nds[i].s << ' ' << nds[j].s << '\n';
	return 0;
}