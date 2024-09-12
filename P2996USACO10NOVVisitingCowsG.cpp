#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
vector<int> g[N];
int n, dp[N][2];
void dfsResolve(int x, int fa) {
    dp[x][1] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa)
            continue;
        dfsResolve(y, x);
        dp[x][1] += dp[y][0];
        dp[x][0] += max(dp[y][1], dp[y][0]);
    }
    return;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsResolve(1, 0);
    printf("%d", max(dp[1][1], dp[1][0]));
    return 0;
}