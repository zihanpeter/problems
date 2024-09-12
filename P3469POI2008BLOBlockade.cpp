#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int n, m, size[N], dfn[N], low[N], timeStaff;
long long ans[N];
void dfs(int x, int fa) {
	size[x] = 1;
	dfn[x] = low[x] = ++timeStaff;
	int sum = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		if (dfn[y] == 0) {
			dfs(y, x);
			size[x] += size[y];
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				ans[x] += 1ll * size[y] * (n - size[y]);
				sum += size[y];
			}
		} else 
			low[x] = min(low[x], dfn[y]);
	}
	ans[x] += 1ll * (n - 1 - sum) * (1 + sum) + n - 1;
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
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == 0) 
			printf("%d\n", 2 * (n - 1));
		else 
			printf("%lld\n", ans[i]);
	}
	return 0;
}
