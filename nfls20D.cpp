#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int cnt = -1, nxt[N << 1], head[N << 1], to[N << 1], tree[N << 2], L[N], R[N];
void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
int n, Q, fa[N], a[N], pos[N], timef, deep[N], jmp[30][N], logn, root = 1;
void dfs(int x) {
	L[x] = ++timef; pos[timef] = x;
	deep[x] = deep[fa[x]] + 1;
	for (int i = head[x]; ~i; i = nxt[i]) {
		int y = to[i];
		if (y ^ fa[x]) dfs(y);
	}
	R[x] = timef;
}
void initJmp() {
	for (int i = 1; i <= n; ++i) jmp[0][i] = fa[i];
	for (int i = 1; i <= logn; ++i) for (int j = 1; j <= n; ++j) 
		jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
}
int lca(int x, int y) {
	if (deep[x] < deep[y]) swap(x, y);
	int t = deep[x] - deep[y], i = 0;
	while (t) {
		if (t & 1) x = jmp[i][x];
		t >>= 1, ++i;
	}
	if (x == y) return x;
	for (int i = logn; ~i; --i) if (jmp[i][x] ^ jmp[i][y]) 
		x = jmp[i][x], y = jmp[i][y];
	return jmp[0][x];
}
void pushUp(int id) { tree[id] = min(tree[id << 1], tree[id << 1 | 1]); }
void build(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[pos[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid); build(id << 1 | 1, mid + 1, r);
	pushUp(id);
}
void update(int id, int l, int r, int x, int v) {
	if (l == r) {
		tree[id] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(id << 1, l, mid, x, v);
	else update(id << 1 | 1, mid + 1, r, x, v);
	pushUp(id);
}
int query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[id];
	int mid = (l + r) >> 1, ans = INF;
	if (L <= mid) ans = min(ans, query(id << 1, l, mid, L, R));
	if (R > mid) ans = min(ans, query(id << 1 | 1, mid + 1, r, L, R));
	return ans;
}
int main() {
	freopen("nfls20D.in", "r", stdin);
	scanf("%d%d", &n, &Q);
	memset(head, -1, sizeof(head));
	int f, v;
	logn = log2(n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &f, &v);
		fa[i] = f, a[i] = v;
		add(i, f), add(f, i);
	}
	dfs(1);
	initJmp();
	build(1, 1, n);
	char c;
	int x, y;
	while (Q--) {
		cin >> c;
		if (c == 'V') {
			scanf("%d%d", &x, &y);
			update(1, 1, n, L[x], y);
		} else if (c == 'E') scanf("%d", &root);
		else {
			scanf("%d", &x);
			if (root == x) printf("%d\n", tree[1]);
			else if (L[x] <= L[root] && R[x] >= R[root]) {
				int t = deep[root] - deep[x] - 1, i = 0, r = root;
				while (t) {
					if (t & 1) r = jmp[i][r];
					t >>= 1, ++i;
				}
				printf("%d\n", min(query(1, 1, n, 1, L[r] - 1), query(1, 1, n, R[r] + 1, n)));
			} else printf("%d\n", query(1, 1, n, L[x], R[x]));
		}
	}
	return 0;
}
