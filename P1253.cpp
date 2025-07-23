#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5e6 + 5, INF = 0x3f3f3f3f3f3f3f3f;
int n, q, a[N], tree[N << 2];
struct node {
	int cover, add;
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

void pushDown(int id) {
	if (lazy[id].cover ^ -INF) {
		lazy[id << 1].cover = lazy[id].cover;
		tree[id << 1] = lazy[id].cover;
		lazy[id << 1 | 1].cover = lazy[id].cover;
		tree[id << 1 | 1] = lazy[id].cover;
		lazy[id << 1].add = lazy[id << 1 | 1].add = 0;
		lazy[id].cover = -INF;
	}
	if (lazy[id].add) {
		lazy[id << 1].add += lazy[id].add;
		lazy[id << 1 | 1].add += lazy[id].add;
		tree[id << 1] += lazy[id].add;
		tree[id << 1 | 1] += lazy[id].add;
		lazy[id].add = 0;
	}
}

void update(int id, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		tree[id] += v;
		lazy[id].add += v;
		return;
	}
	pushDown(id);
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
		lazy[id].cover = x;
		lazy[id].add = 0;
		return;
	}
	pushDown(id);
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
	pushDown(id);
	int mid = (l + r) >> 1, ans = -INF;
	if (L <= mid) {
		ans = max(ans, query(id << 1, l, mid, L, R));
	}
	if (R > mid) {
		ans = max(ans, query(id << 1 | 1, mid + 1, r, L, R));
	}
	return ans;
}

signed main() {
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
	}
	for (int i = 0; i < N; ++i) {
		lazy[i].cover = -INF;
		tree[i] = -INF;
	}
	build(1, 1, n);
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
