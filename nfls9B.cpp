#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
int n, m, q, a[N], maxf[N], sz[N];

vector<int> g[N], v[N];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    int x, y, p;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y), g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j < g[i].size(); ++j) 
            if (g[g[i][j]].size() >= 500) v[i].push_back(g[i][j]);
    while (q--) {
        scanf("%d", &p);
        if (p == 1) {
            scanf("%d%d", &x, &y);
            a[x] += y;
            for (int i = 0; i < v[x].size(); ++i) maxf[v[x][i]] = max(maxf[v[x][i]], a[x]);
        } else {
            scanf("%d", &x);
            maxf[x] = max(maxf[x], a[x]);
            if (g[x].size() < 500)
                for (int i = 0; i < g[x].size(); ++i) maxf[x] = max(maxf[x], a[g[x][i]]);
            printf("%d\n", maxf[x]);
        }
    }
    return 0;
}