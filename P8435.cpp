#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 5e5 + 5, M = 5e6 + 5;
int n, m;
int cnt, head[N], nxt[M], to[M];
int dfn[N], low[N], ts, ansCnt, root;
stack<int> s;
vector<int> ans[N];

void add(int u, int v) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

void dfs(int x, int fa) {
	dfn[x] = low[x] = ++ts;
	if (x == root && !head[x]) {
		ans[++ansCnt].push_back(x);
		return;
	}
	s.push(x);
	for (int i = head[x]; i; i = nxt[i]) {
		int y = to[i];
		if (y == fa) continue;
		if (dfn[y]) low[x] = min(low[x], dfn[y]);
		else {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (dfn[x] <= low[y]) {
				++ansCnt;
				while (s.top() != y) {
					ans[ansCnt].push_back(s.top());
					s.pop();
				}
				ans[ansCnt].push_back(s.top());
				s.pop();
				ans[ansCnt].push_back(x);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		if (u == v) continue;
		add(u, v); add(v, u);
	}
	for (int i = 1; i <= n; ++i) 
		if (!dfn[i]) {
			root = i;
			dfs(i, 0);
		}
	printf("%d\n", ansCnt);
	for (int i = 1; i <= ansCnt; ++i) {
		printf("%d ", ans[i].size());
		for (int j = 0; j < ans[i].size(); ++j) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
