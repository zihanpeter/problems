#include <iostream>
using namespace std;
int n, b, f[255], s[255], d[255], dp[255][255];
int main() {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i) scanf("%d%d", s + i, d + i);
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (dp[i][j]) 
            for (int k = 1; k <= d[j]; ++k) {
                dp[i][j] = max(dp[i - k][j] + 1, dp[i][j - k] + 1);
            }
        }
    }
    printf("%d", dp[n][b]);
    return 0;
}