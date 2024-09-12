#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int n, m, to[N], head[N], nxt[N], cnt = -1, dfn[N], low[N], timef, edc;
void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
stack<int> s;
vector<int> pos[N];
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
            pos[edc].push_back(t);
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
        if (u == v) continue;
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, -1);
    printf("%d\n", edc);
    for (int i = 1; i <= edc; ++i) {
        printf("%d ", pos[i].size());
        for (int j = 0; j < pos[i].size(); ++j) printf("%d ", pos[i][j]);
        printf("\n");
    }
    return 0;
}