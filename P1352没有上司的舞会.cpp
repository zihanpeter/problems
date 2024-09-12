#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 5;
vector<int> g[N];
int n, happy[N], dp[N][2], rudu[N];
void dfsResolve(int x, int fa) {
    dp[x][1] = happy[x];
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
    for (int i = 1; i <= n; ++i) {
        scanf("%d", happy + i);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[v].push_back(u);
        ++rudu[u];
    }
    for (int i = 1; i <= n; ++i) {
        if (!rudu[i]) {
            dfsResolve(i, 0);
            printf("%d", max(dp[i][1], dp[i][0]));
        }
    }
    return 0;
}