#include <iostream>
using namespace std;
const int N = 25;
int n, m, p, q, a[N][N];
long long dp[N][N];
int cx[] = {1, 0};
int cy[] = {0, 1};
int ccx[] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
int ccy[] = {0, 2, -2, 1, -1, 2, -2, 1, -1};
long long dfs(int x, int y) {
    if (x == n && y == m) 
        return dp[x][y] = 1;
    if (dp[x][y]) return dp[x][y];
    for (int i = 0; i < 2; ++i) {
        int tx = cx[i] + x;
        int ty = cy[i] + y;
        if (tx < 0 || tx > n || ty < 0 || ty > m || a[tx][ty] == 1) continue;
        dp[x][y] += dfs(tx, ty);
    }
    return dp[x][y];
}
int main() {
    cin >> n >> m >> p >> q;
    for (int i = 0; i < 9; ++i) {
        int tx = p + ccx[i];
        int ty = q + ccy[i];
        if (tx < 0 || tx > n || ty < 0 || ty > m || a[tx][ty] == 1) continue;
        a[tx][ty] = 1;
    }
    cout << dfs(0, 0) << endl;
    return 0;
}