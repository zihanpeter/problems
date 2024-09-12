#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
vector<int> g[N];
int n, G, minSize = 0x3f3f3f3f, sizeTree[N], deep[N], ans;
void dfsG(int x, int fa) {
    sizeTree[x] = 1;
    int maxSize = -0x3f3f3f3f;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfsG(y, x);
        sizeTree[x] += sizeTree[y];
        maxSize = max(maxSize, sizeTree[y]);
    }
    maxSize = max(maxSize, n - sizeTree[x]);
    if (maxSize < minSize) {
        minSize = maxSize;
        G = x;
    }
    if (maxSize == minSize) {
        G = min(G, x);
    }
}
void dfsSum(int x, int fa, int deph) {
    deep[x] = deph;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfsSum(y, x, deph + 1);
    }
}
int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsG(1, 0);
    dfsSum(G, 0, 0);
    for (int i = 1; i <= n; ++i) 
        ans += deep[i];
    printf("%d %d", G, ans);
    return 0;
}