// 模版：割点
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, head[N], to[N], nxt[N], cnt, dfn[N], low[N], root, timef, cut[N];

void add(int u, int v) {
    nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++timef;
    int son = 0;
    for (int i = head[x]; ~i; i = nxt[i]) {
        int y = to[i];
        if (y != fa) {
            if (!dfn[y]) {
                ++son;
                tarjan(y, x);
                low[x] = min(low[x], low[y]);
                if (low[y] >= dfn[x] && x ^ root) cut[x] = 1;
                if (x == root && son >= 2) cut[x] = 1;
            } else low[x] = min(low[x], dfn[y]);
        } 
    }
}

int main() {
    while (true) {
        memset(head, -1, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(cut, 0, sizeof(cut));
        scanf("%d", &n); if (!n) break;
        int u, v;
        cnt = -1, timef = 0;
        while (true) {
            scanf("%d", &u); if (!u) break;
            char c;
            while (true) {
                scanf("%d%c", &v, &c);
                add(u, v); add(v, u);
                if (c == '\n' || c == '\r') break;
            }
        }
        for (int i = 1; i <= n; ++i) if (!dfn[i]) { root = i; tarjan(i, -1); }
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += cut[i];
        printf("%d\n", ans);
    }
    return 0;
}
