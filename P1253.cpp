#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, q, a[N], tree[N << 2];
struct node {
	int x, y;
} lazy[N << 2];
void pushUp(int id) {
	tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
void build(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushUp(id);
}
void pushDown(int id, int l, int r) {
	int mid = (l + r) >> 1;
	if (lazy[id].x != -1) {
		lazy[id << 1].x = lazy[id].x;
		tree[id << 1] = lazy[id].x;
		lazy[id << 1 | 1].x = lazy[id].x;
		tree[id << 1 | 1] = lazy[id].x;
		lazy[id].x = 0;
	}
	if (lazy[id].y) {
		lazy[id << 1].y += lazy[id].y;
		lazy[id << 1 | 1].y += lazy[id].y;
		tree[id << 1] += lazy[id].y;
		tree[id << 1 | 1] += lazy[id].y;
		lazy[id].y = 0;
	}
}
void update(int id, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		tree[id] += (r - l + 1) * v;
		lazy[id].y += v;
		return;
	}
	pushDown(id, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) {
		update(id << 1, l, mid, L, R, v);
	}
	if (R > mid) {
		update(id << 1 | 1, mid + 1, r, L, R, v);
	}
	pushUp(id);
}

void update2(int id, int l, int r, int L, int R, int x) {
	if (L <= l && r <= R) {
		tree[id] = x;
		lazy[id].x = x;
		lazy[id].y = 0;
		return;
	}
	pushDown(id, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) {
		update2(id << 1, l, mid, L, R, x);
	}
	if (R > mid) {
		update2(id << 1 | 1, mid + 1, r, L, R, x);
	}
	pushUp(id);
}

int query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return tree[id];
	}
	pushDown(id, l, r);
	int mid = (l + r) >> 1, ans = 0;
	if (L <= mid) {
		ans += query(id << 1, l, mid, L, R);
	}
	if (R > mid) {
		ans += query(id << 1 | 1, mid + 1, r, L, R);
	}
	return ans;
}
signed main() {
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
	}
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) lazy[i].x = -1;
	int op, l, r, x;
	for (int i = 1; i <= q; ++i) {
		scanf("%lld%lld%lld", &op, &l, &r);
		if (op == 1) {
			scanf("%lld", &x);
			update2(1, 1, n, l, r, x);
		} 
		else if (op == 2) {
			scanf("%lld", &x);
			update(1, 1, n, l, r, x);
		}
		else {
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}