#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 300, M = 2e5 + 5, INF = 0x3f3f3f3f;
int n, m, s, t, r[N], c[N];
int cnt = 1, to[M], nxt[M], head[M], wei[M];
int deep[M], now[M], ans;
queue<int> q;

void add(int u, int v, int w) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; wei[cnt] = w;
}

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
	scanf("%d%d", &m, &n);
	s = n + m + 1, t = n + m + 2;
	for (int i = 1; i <= m; ++i) scanf("%d", r + i);
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	for (int i = 1; i <= m; ++i) {
		add(s, i, r[i]);
		add(i, s, 0);
	}
	for (int i = m + 1; i <= n + m; ++i) {
		add(i, t, c[i - m]);
		add(t, i, 0);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = m + 1; j <= n + m; ++j) {
			add(i, j, 1);
			add(j, i, 0);
		}
	}
	while (bfs()) ans += dfs(s, INF);
	int sumr = 0;
	for (int i = 1; i <= m; ++i) sumr += r[i];
	if (sumr ^ ans) {
		printf("0");
		return 0;
	}
	printf("1\n");
	for (int i = 1; i <= m; ++i) {
		for (int j = head[i]; j; j = nxt[j]) {
			int y = to[j], w = wei[j];
			if (!w && y ^ s) printf("%d ", y - m);
		}
		printf("\n");
	}
	return 0;
}
