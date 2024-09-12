#include <cstdio>
#include <vector>
using namespace std;
const int N = 5e3 + 5;
int n, m, timeStaff, dfn[N], low[N], g[N][N], g2[N][N], ans, leaves;
bool vis[N];
void dfs(int x, int fa) {
	dfn[x] = low[x] = ++timeStaff;
	for (int i = 1; i <= n; ++i) {
		if (!g[x][i]) 
			continue;
		int y = i;
		if (y == fa) 
			continue;
		else if (dfn[y] == 0) {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x]) {
				g2[x][y] = 1;
				g2[y][x] = 1;
			}
		} else 
			low[x] = min(low[x], dfn[y]);
	}
	return;
}
void dfs2(int x) {
	vis[x] = true;
	for (int i = 1; i <= n; ++i) {
		if (!g[x][i]) 
			continue;
		int y = i;
		if (g2[x][y]) 
			++ans;
		else if (!vis[y])
			dfs2(y);
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = 1;
		g[v][u] = 1;
	}
	for (int i = 1; i <= n; ++i) 
		if (dfn[i] == 0)
			dfs(i, 0);
	for (int i = 1; i <= n; ++i) 
		if (!vis[i]) {
			ans = 0;
			dfs2(i);
			if (ans == 1)
				++leaves;
		}
	printf("%d", (leaves + 1) >> 1);
	return 0;
} 
