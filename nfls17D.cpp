#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, to[N], head[N], nxt[N], cnt = -1, dfn[N], low[N], timef, edc, pos[N], deep[N], father[N], maxDeep, jump[N][100], logn;
void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
stack<int> s;
vector<int> g[N];
void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++timef;
    s.push(x);
    for (int i = head[x]; ~i; i = nxt[i]) {
        int y = to[i];
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
        }
        if (i ^ (fa ^ 1)) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        ++edc;
        int t;
        do {
            t = s.top();
            pos[t] = edc;
            s.pop();
        } while(t != x);
    }
}
void dfs(int x, int fa) {
    deep[x] = deep[fa] + 1;
    maxDeep = max(maxDeep, deep[x]);
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) if (g[x][i] ^ fa) dfs(g[x][i], x);
}
void initJump() {
    logn = log2(edc);
    for (int i = 1; i <= edc; ++i) jump[i][0] = father[i];
    for (int j = 1; j <= logn; ++j) 
        for (int i = 1; i <= edc; ++i) 
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int t = deep[x] - deep[y], i = 0;
    while (t) {
        if (t & 1) x = jump[x][i];
        t >>= 1;
        ++i;
    }
    if (x == y) return x;
    for (int i = logn; i >= 0; --i) {
        if (jump[x][i] == jump[y][i]) continue;
        x = jump[x][i];
        y = jump[y][i];
    }
    return jump[x][0];
}
int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    int u, v;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, -1);
    for (int i = 1; i <= n; ++i) 
        for (int j = head[i]; ~j; j = nxt[j]) {
            int y = to[j];
            if (pos[i] ^ pos[y]) g[pos[i]].push_back(pos[y]);
        }
    dfs(1, 0);
    initJump();
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &u, &v);
        int res = lca(pos[u], pos[v]);
        printf("%d\n", deep[pos[u]] - deep[res] + deep[pos[v]] - deep[res]);
    }
    return 0;
}