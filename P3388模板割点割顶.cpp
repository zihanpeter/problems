#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e4 + 5;
vector<int> g[N];
int n, m, timeStaff, dfn[N], low[N], root;
bool cuts[N];
void dfs(int x, int fa) {
	dfn[x] = ++timeStaff;
	low[x] = dfn[x];
	int children = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		if (dfn[y] == 0) { // 指向孩子的边 
			++children;
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x] && x != root)
				cuts[x] = 1;
			if (x == root && children >= 2) 
				cuts[x] = 1;
		} else // 返祖边 
			low[x] = min(low[x], dfn[y]);
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) 
		if (dfn[i] == 0) {
			root = i;
			dfs(i, 0);
		}
	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		if (cuts[i]) 
			++ans;
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		if (cuts[i])
			printf("%d ", i);
	return 0;
}
