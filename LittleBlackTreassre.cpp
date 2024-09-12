#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e4 + 5;
const int M = 5e4 + 5;
int n, m, q, f[N], deep[N], father[N], jump[N][30], logn, wss[N], minv[N][30];
bool vis[N];
struct node2 {
    int x, w;
};
vector<node2> g[N];
int find(int x) {
    if (f[x] == x) 
        return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) 
        f[fx] = fy;
}
struct node {
    int x, y, w;
} side[M];
bool cmp(node x, node y) {
    return x.w > y.w;
}
void dfs(int x, int fa) {
    // cout << x << endl;
    vis[x] = true;
    deep[x] = deep[fa] + 1;
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].x;
        if (y == fa) 
            continue;
        wss[y] = g[x][i].w;
        dfs(y, x);
    }
}
void initJump() {
    for (int i = 1; i <= n; ++i) {
        jump[i][0] = father[i];
        minv[i][0] = wss[i];
    }
    for (int j = 1; j <= logn; ++j) 
        for (int i = 1; i <= n; ++i) { 
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
            minv[i][j] = min(minv[i][j - 1], minv[jump[i][j - 1]][j - 1]);
        }
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) 
        swap(x, y);
    int dis = deep[x] - deep[y], k = 0;
    int ans = 0x3f3f3f3f;
    while (dis) {
        if (dis & 1) {
            ans = min(ans, minv[x][k]);
            x = jump[x][k];
        }
        ++k;
        dis >>= 1;
    }
    if (x == y) 
        return ans;
    for (int i = logn; i >= 0; --i) {
        if (jump[x][i] == jump[y][i]) 
            continue;
        ans = min(ans, minv[x][i]);
        ans = min(ans, minv[y][i]);
        x = jump[x][i];
        y = jump[y][i];
    }
    ans = min(ans, minv[x][0]);
    ans = min(ans, minv[y][0]);
    return ans;
}
int main() {
    cin >> n >> m;
    logn = log2(n);
    for (int i = 1; i <= n; ++i) 
        f[i] = i;
    for (int i = 1; i <= m; ++i) 
        cin >> side[i].x >> side[i].y >> side[i].w;
    sort(side + 1, side + m + 1, cmp);
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int x = side[i].x, y = side[i].y, w = side[i].w;
        if (find(x) != find(y)) {
            merge(x, y);
            g[x].push_back(node2{y, w});
            g[y].push_back(node2{x, w});
            ++cnt;
        }
    }
    for (int i = 1; i <= n; ++i) 
        if (!vis[i]) 
            dfs(i, 0);
    initJump();
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) 
            cout << -1 << endl;
        else 
            cout << lca(a, b) << endl;
    }
    return 0;
}