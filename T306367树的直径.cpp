#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];
int n, max1 = -0x3f3f3f3f, maxp, max2 = -0x3f3f3f3f;
void dfs1(int x, int step) {
	vis[x] = true;
	if (step > max1) {
		max1 = step;
		maxp = x;
	}
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (vis[y])
			continue;
		dfs1(y, step + 1);
	}
}
void dfs2(int x, int step) {
	vis[x] = true;
	max2 = max(max2, step);
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (vis[y])
			continue;
		dfs2(y, step + 1);
	}
}
int main() {
    scanf("%d", &n);
	int u, v;
    for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);	
    }
	dfs1(1, 0);
	memset(vis, 0, sizeof(vis));
	dfs2(maxp, 0);
	printf("%d", max2);
    return 0;
}
