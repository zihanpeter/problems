#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
int n, cnt, head[N], to[N << 1], nxt[N << 1];
void add(int u, int v) {
	nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}
int mu[N], mv[N], logn, jmp[N][30], dep[N];
void dfs(int x, int f) {
	dep[x] = dep[f] + 1;
	jmp[x][0] = f;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = to[i];
		if (y != f) {
			dfs(y, x);
		}
	}
}

int main() {
	scanf("%d", &n);
	int u, v;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	logn = log2(n);
	for (int j = 1; j <= logn; ++j) {
		for (int i = 1; i <= n; ++i) {
			jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", mu + i, mv + i);
	}
	for (int i = n - 1; i; --i) {
		u = mu[i], v = mv[i];
		
	}
	return 0;
}
