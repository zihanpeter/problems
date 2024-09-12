#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, cnt, nxt[N], head[N], to[N], wei[N], timef, dfn[N], pos[N];
int jmp[30][N], deep[N], len[N], logn, ans;
void add(int u, int v, int w) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; wei[cnt] = w; }
set<int> s;
void dfs(int x, int f) {
    dfn[x] = ++timef, pos[timef] = x;
    jmp[0][x] = f;
    deep[x] = deep[f] + 1;
    for (int i = head[x]; ~i; i = nxt[i]) {
        int y = to[i], w = wei[i];
        if (y ^ f) {
            len[y] = len[x] + w;
            dfs(y, x);
        }
    }
}
void initJmp() {
    for (int i = 1; i <= logn; ++i) for (int j = 1; j <= n; ++j) 
        jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int i = 0, dis = deep[x] - deep[y];
    while (dis) {
        if (dis & 1) x = jmp[i][x];
        dis >>= 1, ++i;
    }
    if (x == y) return x;
    for (i = logn; ~i; --i) 
        if (jmp[i][x] ^ jmp[i][y]) 
            x = jmp[i][x], y = jmp[i][y];
    return jmp[0][x];
}
int calc(int x) {
    if (s.empty()) return 0;
    set<int>::iterator it = s.upper_bound(x);
    int l, r;
    if (it == s.begin() || it == s.end()) l = pos[*s.begin()], r = pos[*s.rbegin()];
    else { l = pos[*it]; --it; r = pos[*it]; }
    x = pos[x];
    return len[x] - len[lca(x, l)] - len[lca(x, r)] + len[lca(l, r)];
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d\n:", i);
        memset(head, -1, sizeof(head));
        memset(jmp, 0, sizeof(jmp));
        memset(deep, 0, sizeof(deep));
        memset(dfn, 0, sizeof(dfn));
        memset(pos, 0, sizeof(pos));
        s.clear();
        timef = 0, cnt = -1, ans = 0;
        scanf("%d%d", &n, &q);
        logn = log2(n);
        int u, v, w;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w), add(v, u, w);
        }
        dfs(1, 0);
        initJmp();
        while (q--) {
            scanf("%d%d", &u, &v);
            if (u == 1 && !s.count(dfn[v])) {
                ans += calc(dfn[v]);
                s.insert(dfn[v]);
            } else if (u == 2 && s.count(dfn[v])) {
                s.erase(dfn[v]);
                ans -= calc(dfn[v]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}