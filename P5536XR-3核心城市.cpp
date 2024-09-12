#include <bits/stdc++.h>
using namespace std;
int n, k, maxDeep1 = -0x3f3f3f3f, point1;
void dfs1(int x, int fa, int deep) {
	if (deep > maxDeep1) {
		maxDeep1 = deep;
		point1 = x;
	}
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		dfs(y, x, deep + 1);
	}
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	g[u].push_back(v);
    	g[v].push_bcak(u);
	}
	dfs1(1, 0, 1);
	dfs2(point1, 
    return 0;
}
