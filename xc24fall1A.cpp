#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 5;
int n, k, q, a[N];
bool mk[N];
int cnt, head[N], nxt[N], to[N];
void add(int u, int v) {
    nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

void dfs(int x, int f) {
    if (mk[x]) a[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = to[i];
        if (y == f) continue;
        dfs(y, x);
        a[x] += a[y];
    }
}

void dfs2(int x, int f) {
    if (a[f]) a[x] += a[f] + 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = to[i];
        if (y == f) continue;
        dfs2(y, x);
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &q);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &u);
        mk[u] = true;
    }
    dfs(1, 0);
    
    return 0;
}