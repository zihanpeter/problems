#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, m, dis[N], cnt[N];
bool vis[N];
struct node { int x, w; };
vector<node> g[N];
queue<int> q;
void spfa() {
	memset(dis, 0x3f, sizeof(dis));
	q.push(0);
	vis[0] = true;
	dis[0] = 0;
	cnt[0] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].x, w = g[x][i].w;
			if (dis[x] + w < dis[y]) {
				dis[y] = dis[x] + w;
				++cnt[y];
				if (cnt[y] >= n) printf("NO"), exit(0);
				if (!vis[y]) q.push(y), vis[y] = true;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int u, v, w;
	for (int i = 1; i <= n; ++i) g[0].push_back(node{i, 0});
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		g[v].push_back(node{u, w});
	}
	spfa();
	for (int i = 1; i <= n; ++i) printf("%d ", dis[i]);
	return 0;
}
