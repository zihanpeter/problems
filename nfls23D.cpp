#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5, M = 1e4 + 405, INF = 0x3f3f3f3f;
int n, F, D, s, t;
struct node {
	int f, d, fi[N], di[N];
} cow[N];
int cnt = 1, nxt[M], head[M], to[M], wei[M], deep[M], now[M];
void add(int u, int v, int w) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; wei[cnt] = w;
}
queue<int> q;
bool bfs() {
	memset(deep, 0, sizeof(deep));
	while (!q.empty()) q.pop();
	q.push(s);
	deep[s] = s;
	now[s] = head[s];
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = to[i], w = wei[i];
			if (deep[y] || !w) continue;
			deep[y] = deep[x] + 1;
			now[y] = head[y];
			if (y == t) return true;
			q.push(y);
		}
	}
	return false;
}
int dfs(int x, int flow) {
	if (x == t) return flow;
	int rest = flow, k;
	for (int i = now[x]; i && rest; i = nxt[i]) {
		int y = to[i], w = wei[i];
		now[x] = i;
		if (deep[y] ^ deep[x] + 1 || !w) continue;
		k = dfs(y, min(rest, w));
		if (!k) deep[y] = 0;
		wei[i] -= k;
		wei[i ^ 1] += k;
		rest -= k;
	}
	return flow - rest;
}
int main() {
	scanf("%d%d%d", &n, &F, &D);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &cow[i].f, &cow[i].d);
		for (int j = 1; j <= cow[i].f; ++j) {
			scanf("%d", &cow[i].fi[j]);
			add(cow[i].fi[j], F + D + i, 1), add(F + D + i, cow[i].fi[j], 0);
		}
		for (int j = 1; j <= cow[i].d; ++j) {
			scanf("%d", &cow[i].di[j]);
			add(F + D + n + i, F + cow[i].di[j], 1), add(F + cow[i].di[j], F + D + n + i, 0);
		}
	}
	s = F + D + n * 2 + 1, t = F + D + n * 2 + 2;
	for (int i = 1; i <= F; ++i) add(s, i, 1), add(i, s, 0);
	for (int i = F + 1; i <= F + D; ++i) add(i, t, 1), add(t, i, 0);
	for (int i = F + D + 1; i <= F + D + n; ++i) 
		add(i, i + n, 1), add(i + n, i, 0);
	int ans = 0;
	while (bfs()) ans += dfs(s, INF);
	printf("%d", ans);
	return 0;
}
