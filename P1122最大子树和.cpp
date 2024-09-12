#include <bits/stdc++.h>
using namespace std;
const int N = 16000 + 5;
vector<int> g[N];
int n, beauty[N], maxBeauty = -0x3f3f3f3f, maxPoint, size[N];
void dfsResolve(int x, int fa) {
    size[x] = beauty[x];
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfsResolve(y, x);
        size[x] = max(size[x] + size[y], size[x]);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", beauty + i);
        if (beauty[i] > maxBeauty) {
            maxBeauty = beauty[i];
            maxPoint = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsResolve(maxPoint, 0);
    printf("%d", size[maxPoint]);
    return 0;
}