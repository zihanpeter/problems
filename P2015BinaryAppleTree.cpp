#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int n, dp[N][N], q, l[N], r[N], info[N];
struct node {
    int p, w;
};
vector<node> g[N];
void dfs(int x, int fa) {
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].p;
        if (y == fa) 
            continue;
        if (l[x] != 0) 
            l[x] = y;
        else 
            r[x] = y;
        info[y] = g[x][i].w;
        dfs(y, x);
    }
    return;
}
int dfsResolve(int i, int j) {
    if (dp[i][j] != -1) 
        return dp[i][j];
    if (j == 0) 
        return dp[i][j] = 0;
    dp[i][j] = max(dfsResolve(l[i], j - 1) + info[l[i]], dfsResolve(r[i], j - 1) + info[r[i]]);
    for (int k = 0; k <= j; ++k) 
        dp[i][j] = max(dp[i][j], dfsResolve(l[i], k) + dfsResolve(r[i], j - 2 - k) + info[l[i]] + info[r[i]]);
    return dp[i][j];
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(node{v, w});
        g[v].push_back(node{u, w});
    }
    dfs(1, 0);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -1;
        }
    }
    printf("%d", dfsResolve(1, q));
    return 0;
}