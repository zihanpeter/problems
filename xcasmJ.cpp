#include <iostream>
#include <climits>
#define int long long
using namespace std;
const int N = 5e2 + 5, INF = LLONG_MAX;
int n, m, q, g[N][N];

signed main() {
    scanf("%lld%lld%lld", &n, &m, &q);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            if (i ^ j) g[i][j] = INF;
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%lld%lld%lld", &u, &v, &w);
        g[u][v] = g[v][u] = w;
    }
    for (int k = 1; k <= n; ++k) 
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) {
                if (g[i][k] == INF || g[k][j] == INF) g[i][j] = min(g[i][j], LLONG_MAX);
                else g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
    while (q--) {
        scanf("%lld%lld", &u, &v);
        if (g[u][v] == INF) printf("-1\n");
        else  printf("%lld\n", g[u][v]);
    }
    return 0;
}