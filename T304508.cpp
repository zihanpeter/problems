#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, col[N], dis[N];
vector<int> g[N];
void dfs(int x, int fa) {
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) continue;
		dis[y] = dis[x] + 1;
		dfs(y, x);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) scanf("%d", col + i);
	for (int i = 1; i <= n; ++i) 
		if (col[i]) {
			dfs(i, 0);
			break;
		}
	int max_dis = -INF, maxi;
	for (int i = 1; i <= n; ++i) 
		if (dis[i] > max_dis && col[i]) {
			max_dis = dis[i];
			maxi = i;
		}
	dis[maxi] = 0;
	dfs(maxi, 0);
	max_dis = -INF;
	for (int i = 1; i <= n; ++i) max_dis = max(max_dis, dis[i]);
	printf("%d", max_dis);
	return 0;
} 
