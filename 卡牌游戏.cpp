#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int num[N], n, dp[N][N];
int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> num[i];
    for (int l = 3; l <= n; ++l) {
        for (int i = 1; i <= n; ++i) {
            int j = i + l - 1;
            if (l == 3) {
                dp[i][j] = num[i] * num[i + 1] * num[j];
            } else {
                for (int k = i + 1; k < j; ++k) {
                    int xans = num[i] * num[k] * num[j] + dp[i][k] + dp[k][i];
                    dp[i][j] = min(dp[i][j], xans);
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int k = 2; k < n; ++k) {
        ans = min(ans, dp[1][k] + dp[k][n]);
    }
    cout << ans << endl;
    return 0;
}
