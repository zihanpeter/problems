#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, cnt = -1, nxt[N], to[N], head[N], timef, dfn[N], low[N], pos[N], rudu[N], scc, chudu[N];
bool vis[N];
stack<int> s;
void add(int u, int v) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++timef;
	s.push(x); vis[x] = true;
	for (int i = head[x]; ~i; i = nxt[i]) {
		int y = to[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		} else if (vis[y]) low[x] = min(low[x], dfn[y]); 
	}
	if (dfn[x] == low[x]) {
		++scc;
		int t;
		do {
			t = s.top();
			s.pop();
			pos[t] = scc;
			vis[t] = false;
		} while (t ^ x);
	}
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
	for (int x = 1; x <= n; ++x) 
		for (int j = head[x]; ~j; j = nxt[j]) {
			int y = to[j];
			if (pos[x] != pos[y]) {
				++rudu[pos[y]];
				++chudu[pos[x]];
			}
		}
	int rudu0 = 0, chudu0 = 0;
	for (int i = 1; i <= scc; ++i) {
		if (!rudu[i]) ++rudu0;
		if (!chudu[i]) ++chudu0;
	}
	printf("%d", max(rudu0, chudu0));
	return 0;
}
