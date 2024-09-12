#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m, w[N], dfsSort[N], pos1[N], pos2[N], last;
vector<int> g[N];
void dfs(int x, int fa) {
	dfsSort[++last] = w[x];
	pos1[x] = last;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		dfs(y, x);
	}
	dfsSort[++last] = -w[x];
	pos2[x] = last;
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", w + i);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= last; ++i) 
		dfsSort[i] += dfsSort[i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		printf("%d ", dfsSort[pos1[x]]);
	}
	return 0;
}
