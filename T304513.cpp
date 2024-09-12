#include <iostream>
#include <stack>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m, nn;
int head[N], nxt[N], to[N], cnt;
int h2[N], nx2[N], to2[N], cnt2;
int ts, low[N], dfn[N], sz[N], ans[N];
stack<int> s;
void add(int u, int v) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}
void add2(int u, int v) {
	nx2[++cnt2] = h2[u]; h2[u] = cnt2; to2[cnt2] = v;
}
void dfs(int x) {
	dfn[x] = low[x] = ++ts;
	s.push(x);
	int y;
	for (int i = head[x]; i; i = nxt[i]) {
		y = to[i];
		if (!dfn[y]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				add2(++nn, x); add2(x, nn);
				while (s.top() != y) {
					add2(nn, s.top()); add2(s.top(), nn);
					s.pop();
				}
				add2(nn, s.top()); add2(s.top(), nn);
				s.pop();
			}
		} else low[x] = min(low[x], dfn[y]);
	}
}
void dfs2(int x, int fa) {
	if (x <= n) sz[x] = 1;
	int k = sz[x], y;
	for (int i = h2[x]; i; i = nx2[i]) {
		y = to2[i];
		if (y == fa) continue;
		dfs2(y, x);
		ans[x] += k * sz[x] * sz[y];
		sz[x] += sz[y];
	}
	ans[x] += k * sz[x] * (n - sz[x]);
}
signed main() {
	scanf("%lld%lld", &n, &m);
	nn = n;
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%lld%lld", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1);
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i) printf("%lld\n", ans[i] << 1);
	return 0;
}
