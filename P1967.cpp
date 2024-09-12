#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 2e4 + 5, M = 5e4 + 5;
int cnt = -1, nxt[M], head[M], to[M], p;
void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
int n, m, f[N], deep[N], jmp[30][N], logn, a[N];
bool vis[N];
struct node {
    int u, v, w;
} sd[M];
bool cmp(node x, node y) { return x.w > y.w; }
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void dfs(int x, int fa) {
	vis[x] = true;
    deep[x] = deep[fa] + 1;
    jmp[0][x] = fa;
    for (int i = head[x]; ~i; i = nxt[i]) {
        int y = to[i];
        if (y ^ fa) dfs(y, x);
    }
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int t = deep[x] - deep[y], i = 0;
    while (t) {
        if (t & 1) x = jmp[i][x];
        t >>= 1, ++i;
    }
    if (x == y) return x;
    for (i = logn; ~i; --i) 
        if (jmp[i][x] ^ jmp[i][y]) x = jmp[i][x], y = jmp[i][y];
    return jmp[0][x];
}
int main() {
    freopen("P1967.in", "r", stdin);
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    logn = log2(n);
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &sd[i].u, &sd[i].v, &sd[i].w);
    sort(sd + 1, sd + m + 1, cmp);
    p = n;
    for (int i = 1; i <= m; ++i) {
        int u = sd[i].u, v = sd[i].v, w = sd[i].w;
        int fx = find(u), fy = find(v);
        if (fx ^ fy) {
			++p;
            f[fx] = f[fy] = f[p] = p;
            add(p, fx), add(fx, p);
            add(p, fy), add(fy, p);
            a[p] = w;
        }
    }
	for (int i = 1; i <= p; ++i) if (!vis[i]) dfs(find(i), 0);
    // initJmp
    for (int i = 1; i <= logn; ++i) for (int j = 1; j <= p; ++j) 
		jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        if (find(x) ^ find(y)) printf("-1\n");
        else printf("%d\n", a[lca(x, y)]);
    }
    return 0;
}
