#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int n, sizeT[N], ans = 0x3f3f3f3f;
void dfs(int x, int fa) {
	sizeT[x] = 1;
	int maxSize = -0x3f3f3f3f;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		dfs(y, x);
		sizeT[x] += sizeT[y];
		maxSize = max(maxSize, sizeT[y]);
	}
	maxSize = max(maxSize, n - sizeT[x]);
	ans = min(ans, maxSize);
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
	printf("%d", ans);
	return 0;
}
