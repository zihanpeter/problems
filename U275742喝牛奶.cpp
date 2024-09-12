#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, d[N], logn, deep[N], father[N], up[N][30], maxD[N][30];
vector<int> g[N];
void dfs(int x, int fa) {
    deep[x] = deep[fa] + 1;
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfs(y, x);
    }
	return;
}
void initUp() {
	for (int i = 1; i <= n; ++i) {
		up[i][0] = father[i];
		maxD[i][0] = max(d[i], d[father[i]]);
	}
	for (int j = 1; j <= logn; ++j) {
		for (int i = 1; i <= n; ++i) {
			up[i][j] = up[up[i][j - 1]][j - 1];
			maxD[i][j] = max(maxD[i][j - 1], maxD[up[i][j - 1]][j - 1]);
		}
	} 
	return;
}
int lca(int x, int y) {
	if (x == y) {
		return max(d[x], d[y]);
	}
	if (deep[x] < deep[y]) 
		swap(x, y);
	int dis = deep[x] - deep[y];
	int k = 0;
	int ans = max(d[x], d[y]);
	while(dis) {
		if (dis % 2 == 1) {
			ans = max(ans, maxD[x][k]);
			x = up[x][k];
		}
		dis /= 2;
		++k;
	}
	if (x == y) {
		ans = max(ans, d[x]);
		return ans;
	}
	for (int i = logn; i >= 0; --i) {
		if (up[x][i] == up[y][i])
			continue;
		ans = max(ans, maxD[x][i]);
		ans = max(ans, maxD[y][i]);
		x = up[x][i];
		y = up[y][i];
	}
	ans = max(ans, maxD[x][0]);
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", d + i);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	logn = log2(n);
	dfs(1, 0);
	initUp();
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}
