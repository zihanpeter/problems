#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, dis[N], cnt[N];
bool vis[N];
struct node{ int x, w; };
vector<node> g[N];
queue<int> q;
bool spfa() {
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(n + 1);
	vis[n + 1] = true, dis[n + 1] = 0, cnt[n + 1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].x, w = g[x][i].w;
			if (dis[x] + w < dis[y]) {
				dis[y] = dis[x] + w;
				++cnt[y];
				if (cnt[y] >= n) return false;
				if (!vis[y]) q.push(y), vis[y] = true;
			}
		}
	}
	return true;
}
int main() {
	int W;
	scanf("%d", &W);
	while (W--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n + 1; ++i) g[i].clear();
		for (int i = 1; i <= n; ++i) g[n + 1].push_back(node{i, 0});
		int s, t, v;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &s, &t, &v);
			g[s - 1].push_back(node{t, v});
			g[t].push_back(node{s - 1, -v});
		}
		if (spfa()) printf("true\n");
		else printf("false\n");
	}
	return 0;
}
