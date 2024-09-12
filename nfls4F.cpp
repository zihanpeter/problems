#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, cnt, head[N], nxt[N], to[N], deep[N];

void add(int u, int v) {
    nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}

void dfs(int x, int fa) {
    deep[x] = deep[fa] + 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = to[i];
        if (y == fa) continue;
        dfs()
    }
}

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    return 0;
}