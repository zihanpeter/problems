#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], lib[N], tree[N << 2][10], sizet[N << 2];
struct node {
	string s; int x;
} nds[N];

void push_up(int id) {
	for (int i = 0; i < 5; ++i) {
		tree[id][i] = tree[id << 1][i] + tree[id << 1 | 1][((i - sizet[id << 1]) % 5 + 5) % 5];
	}
}

void update(int id, int l, int r, int x, int v) {
	if (l == r) {
		v > 0 ? ++sizet[id] : --sizet[id];
		tree[id][1] = v;
		return;
	}
	v > 0 ? ++sizet[id] : --sizet[id];
	int mid = l + r >> 1;
	if (x <= mid) update(id << 1, l, mid, x, v);
	else update(id << 1 | 1, mid + 1, r, x, v);
	push_up(id);
} 

main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		cin >> nds[i].s;
		if (nds[i].s == "add" || nds[i].s == "del") {
			scanf("%lld", &nds[i].x);
			a[i] = nds[i].x;
		}
	}
	sort(a + 1, a + n + 1);
	int m = unique(a + 1, a + n + 1) - a - 1;
	for (int i = 1; i <= n; ++i) {
		if (nds[i].s == "add" || nds[i].s == "del") {
			int t = nds[i].x;
			nds[i].x = lower_bound(a + 1, a + m + 1, nds[i].x) - a - 1;
			lib[nds[i].x] = t;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (nds[i].s == "add") update(1, 1, m, nds[i].x, lib[nds[i].x]);
		else if (nds[i].s == "del") update(1, 1, m, nds[i].x, 0);
		else printf("%lld\n", tree[1][3]);
	}
	return 0;
}
