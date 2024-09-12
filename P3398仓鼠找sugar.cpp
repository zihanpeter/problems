#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int n, q, deep[N], father[N], logn, up[N][30], lic;
bool vis[N];
void dfs(int x, int fa) {
	deep[x] = deep[fa] + 1;
	father[x] = fa;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		dfs(y, x);
	}
}
void initUp() {
	for (int i = 1; i <= n; ++i) 
		up[i][0] = father[i];
	for (int j = 1; j <= logn; ++j) 
		for (int i = 1; i <= n; ++i) 
			up[i][j] = up[up[i][j - 1]][j - 1];
	return;
}
int lca(int x, int y) {
	if (deep[x] < deep[y]) 
		swap(x, y);
	int dis = deep[x] - deep[y], k = 0;
	while (dis) {
		if (dis % 2 == 1) 
			x = up[x][k];
		dis /= 2;
		++k;
	}
	if (x == y) 
		return x;
	for (int i = logn; i >= 0; --i) {
		if (up[x][i] == up[y][i]) 
			continue;
		x = up[x][i];
		y = up[y][i];
	}
	return up[x][0];
}
void dfsFindMy1(int x) {
	if (x == lic) 
		return;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (vis[y] == true) 
			continue;
		vis[y] = true;
		dfs(y);
		vis[y] = false;
	}
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	logn = log2(n);
	initUp();
	for (int i = 1; i <= q; ++i) {
		memset(vis, 0, sizeof(vis));
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		lic = lca(u, v);
		vis[u] = true;
		dfsFindMy1(u);
		dfsFindMy1(v);
		
	}
	return 0;
} 
