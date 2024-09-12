#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 5e4 + 5;
int n, maxx1, maxx2, maxs1, maxs2, vis[N];
vector<int> g[N];
void dfs1(int x, int step) {
    if (step > maxs1) {
        maxs1 = step;
        maxx1 = x;
    }
    vis[x] = true;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (vis[y]) continue;
        dfs1(y, step + 1);
    }
}
void dfs2(int x, int step) {
    if (step > maxs2) {
        maxs2 = step;
        maxx2 = x;
    }
    vis[x] = true;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (vis[y]) continue;
        dfs2(y, step + 1);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1, 0);
    memset(vis, 0, sizeof(vis));
    dfs2(maxx1, 0);
    cout << maxs2 << endl;
    return 0;
}