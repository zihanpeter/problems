#include <iostream>
using namespace std;
const int N = 1e2 + 5;
int n, m, a[N][N], dp[N][N];
bool vis[N][N];
int cx[] = {1, -1, 0, 0};
int cy[] = {0, 0, 1, -1};
int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    // cout << x << ' ' << y << ' ' << dp[x][y] << endl;
    for (int i = 0; i < 4; ++i) {
        int tx = cx[i] + x;
        int ty = cy[i] + y;
        if (tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] >= a[x][y] || vis[tx][ty]) continue;
        vis[tx][ty] = true;
        dp[x][y] = max(dp[x][y], dfs(tx, ty) + 1);
        vis[tx][ty] = false;
    }
    return dp[x][y];
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;   
}