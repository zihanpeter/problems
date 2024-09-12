#include <cstdio>
#include <vector>
using namespace std;
const int N = 5e4 + 5;
vector<int> g[N];
int n, m, timeStaff, dfn[N], low[N], ans;
bool vis[N];
void dfs(int x, int fa) {
	dfn[x] = low[x] = ++timeStaff;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		else if (dfn[y] == 0) {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x]) 
				++ans;
		} else 
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
	int res = 0;
	for (int i = 1; i <= n; ++i) 
		if (dfn[i] == 0) {
			ans = 0;
			dfs(i, 0);
			res += ans + 1;
		}
	printf("%d", res);
	return 0;
} 
