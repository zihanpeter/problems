#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n, m, x[N], y[N];
bool vis[N];
vector<int> g[N];
int minx, miny, maxx, maxy, ans = 0x3f3f3f3f;

void dfs(int u) {
    minx = min(minx, x[u]);
    maxx = max(maxx, x[u]);
    miny = min(miny, y[u]);
    maxy = max(maxy, y[u]);
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (vis[v]) continue;
        vis[v] = true;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            minx = x[i], miny = y[i], maxx = x[i], maxy = y[i];
            dfs(i);
            ans = min(ans, 2 * (maxx - minx + maxy - miny));
        }
    }
    cout << ans;
    return 0;
}