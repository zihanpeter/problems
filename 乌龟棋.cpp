#include <iostream>
using namespace std;
int v[355], p[125], dp[41][41][41][41], tong[5];
int dfs(int a, int b, int c, int d) {
    if (a == 0 && b == 0 && c == 0 && d == 0) return dp[0][0][0][0] = v[1];
    if (dp[a][b][c][d]) return dp[a][b][c][d];
    dp[a][b][c][d] = v[a*1 + b*2 + c*3 + d*4 + 1];
    int ans = -0x3f3f3f3f;
    if (a > 0) ans = max(ans, dfs(a-1, b, c, d));
    if (b > 0) ans = max(ans, dfs(a, b-1, c, d));
    if (c > 0) ans = max(ans, dfs(a, b, c-1, d));
    if (d > 0) ans = max(ans, dfs(a, b, c, d-1));
    return dp[a][b][c][d] = dp[a][b][c][d] + ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        cin >> v[i];
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
        ++tong[p[i]];
    }
    cout << dfs(tong[1], tong[2], tong[3], tong[4]) << endl;
    return 0;
}