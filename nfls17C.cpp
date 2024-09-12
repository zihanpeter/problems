#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, to[N], head[N], nxt[N], cnt = -1, dfn[N], low[N], timef, edc, pos[N], rudu[N];
void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
stack<int> s;
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
int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    int u, v;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    tarjan(1, -1);
    for (int i = 1; i <= n; ++i) 
        for (int j = head[i]; ~j; j = nxt[j]) {
            int y = to[j];
            if (pos[i] ^ pos[y]) ++rudu[pos[i]];
        }
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        if (rudu[i] == 1) ++ans;
    printf("%d", (ans + 1) / 2);
    return 0;
}