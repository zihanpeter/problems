#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> g[N];
int n, m, s, deep[N], father[N], jump[N][50], logn;
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
int lca(int x, int y) {
    if (deep[x] < deep[y])
        swap(x, y);
    int t = deep[x] - deep[y], i = 0;
    while (t) {
        if (t % 2 == 1) 
            x = jump[x][i];
        t /= 2;
        ++i;
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
int main() {
    scanf("%d%d%d", &n, &m, &s);
    logn = log2(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s, 0);
    for (int i = 1; i <= n; ++i) {
        jump[i][0] = father[i];
    }
    for (int j = 1; j <= logn; ++j) {
        for (int i = 1; i <= n; ++i) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}