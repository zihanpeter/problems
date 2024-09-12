#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int maxv[4 * N], n, a[N], m;
void pushup(int id) {
	maxv[id] = max(maxv[id << 1], maxv[id << 1 | 1]);
}
void build(int id, int l, int r) {
	if (l == r) {
		maxv[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushup(id);
}
void update(int id, int l, int r, int x, int v) {
	if (l == r) {
		maxv[id] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) 
		update(id << 1, l, mid, x, v);
	else 
		update(id << 1 | 1, mid + 1, r, x, v);
	pushup(id);
}
int query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) 
		return maxv[id];
	int mid = (l + r) >> 1;
	int ans = -INF;
	if (L <= mid) 
		ans = max(ans, query(id << 1, l, mid, L, R));
	if (R > mid) 
		ans = max(ans, query(id << 1 | 1, mid + 1, r, L, R));
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	build(1, 1, n);
	char c;
	int x, y;
	while (m--) {
		cin >> c >> x >> y;
		if (c == 'Q') 
			cout << query(1, 1, n, x, y) << endl;
		else
			update(1, 1, n, x, y);
	}
	return 0;
} 
