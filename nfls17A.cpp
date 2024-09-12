// 模版：割边
#include <bits/stdc++.h>
using namespace std;
const int N = 6e4 + 5;
int n, m, cnt = -1, to[N], nxt[N], head[N], dfn[N], low[N], timef, ans;
void add(int x, int y) {
	nxt[++cnt] = head[x]; head[x] = cnt; to[cnt] = y;
}
void tarjan(int x, int fa) {
	dfn[x] = low[x] = ++timef;
	for (int i = head[x]; ~i; i = nxt[i]) {
		int y = to[i];
		if (!dfn[y]) {
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x]) ++ans;
		}
		if (i ^ (fa ^ 1)) low[x] = min(low[x], dfn[y]);
	}
}
int main() {
	while (true) {
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		timef = 0, cnt = -1, ans = 0;
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		int x, y;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, -1);
		printf("%d\n", ans);
	}
	return 0;
}
