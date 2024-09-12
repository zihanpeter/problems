#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, nxt[N], head[N], to[N], cnt = -1, dfn[N], low[N], timef, scc, pos[N];
bool vis[N];
stack<int> s;
void add(int u, int v) {
    nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
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
    if (dfn[x] == low[x]) {
        ++scc;
        int t;
        do {
            t = s.top();
            s.pop();
            vis[t] = false;
            pos[t] = scc;
        } while (x ^ t);
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
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &u, &v);
        if (pos[u] == pos[v]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}