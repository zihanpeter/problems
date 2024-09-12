#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
int n, m, dis[N], logn, father[N], up[N][30], deep[N];
struct node {
	int p, w;
};
vector<node> g[N];
void dfs(int x, int fa) {
	deep[x] = deep[fa] + 1;
	father[x] = fa;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i].p;
		if (y == fa) 
			continue;
		dis[y] = dis[x] ^ g[x][i].w;
		dfs(y, x);
	}
	return;
}
int lca(int x, int y) {
	if (deep[x] < deep[y])
		swap(x, y);
	int t = deep[x] - deep[y], i = 0;
	while (t) {
		if (t % 2) 
			x = up[x][i];
		t /= 2;
		++i;
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
void initUp() {
	for (int i = 1; i <= n; ++i) 
		up[i][0] = father[i];
	for (int j = 1; j <= logn; ++j) 
		for (int i = 1; i <= n; ++i) 
			up[i][j] = up[up[i][j - 1]][j - 1];
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(node{v, w});
		g[v].push_back(node{u, w});
	}
	dfs(1, 0);
	logn = log2(n);
	initUp();
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		int mid = lca(x, y);
		printf("%d\n", (dis[x] ^ dis[mid]) ^ (dis[y] ^ dis[mid]));
	}
	return 0;
}
