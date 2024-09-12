#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int cnt = -1, head[N], nxt[N], to[N];
void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
int timef, dfn[N], low[N], scc;
bool vis[N];
int n, m1, m2, g[605][605], ans;
stack<int> s;
vector<int> scs[N];
void count() {
    int x, y, anst = 0;
    for (int i = 0; i < scs[scc].size(); ++i) {
        for (int j = 0; j < scs[scc].size(); ++j) {
            x = scs[scc][i], y = scs[scc][j];
            anst = max(anst, g[x][y]);
        }
    }
    ans += anst + 1;
}
void tarjan(int x) {
    dfn[x] = low[x] = ++timef;
    s.push(x);
    vis[x] = true;
    for (int i = head[x]; ~i; i = nxt[i]) {
        int y = to[i];
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y]) low[x] = min(low[x], low[y]);
    }
    if (low[x] == dfn[x]) {
        ++scc;
        int t;
        do {
            t = s.top();
            s.pop();
            vis[t] = false;
            scs[scc].push_back(t);
        } while (t ^ x);
        count();
    }
}
int main() {
    memset(g, 0x3f, sizeof(g));
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= n; ++i) g[i][i] = 0;
    int u, v;
    for (int i = 1; i <= m1; ++i) {
        scanf("%d%d", &u, &v);
        g[u][v] = min(g[u][v], 1), g[v][u] = min(g[v][u], -1);
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= m2; ++i) {
        scanf("%d%d", &u, &v);
        g[v][u] = min(g[v][u], 0);
        add(v, u);
    }
    for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) 
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= n; ++i) if (g[i][i] < 0) { printf("NIE"); return 0; }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
    printf("%d", ans);
    return 0;
}