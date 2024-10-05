#include <iostream>
#include <cmath>
using namespace std;
const int N = 4e5 + 5, INF = 0x3f3f3f3f;
int n, dep[N], jmp[N][30], logn;
int cnt, head[N], to[N], nxt[N];

void add(int u, int v) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

void dfs(int x, int f) {
	dep[x] = dep[f] + 1;
	jmp[x][0] = f;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = to[i];
		if (y == f) continue;
		dfs(y, x);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y], i = 0;
	while (t) {
		if (t & 1) x = jmp[x][i];
		t >>= 1;
		++i;
	}
	if (x == y) return x;
	for (int i = logn; i >= 0; --i) 
		if (jmp[x][i] ^ jmp[y][i]) {
			x = jmp[x][i];
			y = jmp[y][i];
		}
	return jmp[x][0];
}

int dis(int x, int y, int z) {
	return dep[x] - dep[z] + dep[y] - dep[z];
}

int main() {
	scanf("%d", &n);
	logn = log2(n);
	int u, v;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	int p1, p2, maxf = -INF;
	for (int i = 1; i <= n; ++i) 
		if (dep[i] > maxf) {
			maxf = dep[i];
			p1 = i;
		}
	maxf = -INF;
	dfs(p1, 0);
	for (int i = 1; i <= n; ++i) 
		if (dep[i] > maxf) {
			maxf = dep[i];
			p2 = i;
		}
	dfs(1, 0);
	for (int i = 1; i <= logn; ++i) 
		for (int j = 1; j <= n; ++j) 
			jmp[j][i] = jmp[jmp[j][i - 1]][i - 1];
	for (int i = 1; i <= n; ++i) 
		printf("%d ", max(dis(i, p1, lca(i, p1)), dis(i, p2, lca(i, p2))));
	return 0;
}
