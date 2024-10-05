#include <iostream>
using namespace std;
const int N = 205, INF = 0x3f3f3f3f;
int a[N], n, dp[N][N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= n << 1; i++) a[i] += a[i - 1];
    n <<= 1;
    for (int len = 2; len <= n >> 1; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l; k < r; ++k) 
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + (a[r] - a[l-1]));
        } 
    }
    int minAns = INF;
    for (int i = 2; i <= n; ++i){
        if (!dp[i][(n >> 1) + i - 1]) continue;
        minAns = min(minAns, dp[i][(n >> 1) + i - 1]);
    }
    printf("%d", minAns);
    return 0;
}