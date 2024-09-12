#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, dep[N], jmp[30][N], sz[N];
vector<int> g[N];

void dfs(int x, int fa) {
	jmp[0][x] = fa;
	dep[x] = dep[fa] + 1;
	sz[x] = 1;
	for (int i = 0; i < g[x].size(); ++i) 
		if (g[x][i] ^ fa) {
			dfs(g[x][i], x);
			sz[x] += sz[g[x][i]];
		}
}

void initJump() {
	for (int i = 1; i <= 20; ++i) for (int j = 1; j <= n; ++j) 
		jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	int dis = dep[y] - dep[x], t = 0;
	while (dis) {
		if (dis & 1) y = jmp[t][y];
		dis >>= 1;
		++t;
	}
	if (x == y) return x;
	for (int i = 20; ~i; --i) {
		if (jmp[i][x] == jmp[i][y]) continue;
		x = jmp[i][x], y = jmp[i][y];
	}
	return jmp[0][x];
}

int jump(int x, int y) {
	if (!y) return x;
	int i = 0;
	while (y) {
		if (y & 1) x = jmp[i][x];
		y >>= 1;
		++i;
	}
	return x;
}

int main() {
	scanf("%d", &n);
	int u, v;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	initJump();
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &u, &v);
		if (u == v) {
			printf("%d\n", sz[1]);
			continue;
		}
		
		int res = lca(u, v);
		int dis = dep[u] - dep[res] + dep[v] - dep[res], 
			disl = dep[u] - dep[res], 
			disr = dep[v] - dep[res];
		if (dis & 1) {
			printf("%d\n", 0);
			continue;
		}
		if (disl == disr) {
			printf("%d\n", n - sz[jump(u, disl - 1)] - sz[jump(v, disr - 1)]);
			continue;
		}
		if (disl > disr) swap(u, v), swap(disl, disr);
		printf("%d\n", sz[jump(v, dis / 2)] - sz[jump(v, dis / 2 - 1)]);
	}
	return 0;
}