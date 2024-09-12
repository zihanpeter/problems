#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
int n, m, logn, deep[N], father[N], jump[N][30], w[N];
vector<int> g[N];
void dfs(int x, int fa) {
    deep[x] = deep[fa] + 1;
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfs(y, x);
    }
}
void initJump() {
    for (int i = 1; i <= n; ++i) 
        jump[i][0] = father[i];
    for (int j = 1; j <= logn; ++j) 
        for (int i = 1; i <= n; ++i) 
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) 
        swap(x, y);
    int dis = deep[x] - deep[y], k = 0;
    while (dis) {
        if (dis & 1) 
            x = jump[x][k];
        ++k;
        dis /= 2;
    }
    if (x == y) 
        return x;
    for (int i = logn; i >= 0; --i) {
        if (jump[x][i] == jump[y][i]) 
            continue;
        x = jump[x][i];
        y = jump[y][i];
    }
    return jump[x][0];
}
int dfs2(int x, int fa) {
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        w[x] += dfs2(y, x);
    }
    return w[x];
}
int main() {
    scanf("%d", &n);
    logn = log2(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    initJump();
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++w[x]; ++w[y];
        w[lca(x, y)] -= 2;
    }
    dfs2(1, 0);
    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (w[i] == 0) 
            ans += m;
        else if (w[i] == 1) 
            ++ans;
    }
    printf("%lld", ans);
    return 0;
}
