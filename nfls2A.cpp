#include <iostream>
using namespace std;
const int N = 2005;
int n, V, s[N], vol[N], wor[N], dp[N], cnt, vol2[N * 50], wor2[N * 50];
int main() {
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", vol + i, wor + i, s + i);
        for (int t = 1; t <= s[i]; t <<= 1) {
            s[i] -= t;
            vol2[++cnt] = t * vol[i];
            wor2[cnt] = t * wor[i];
        }
        if (s[i]) {
            vol2[++cnt] = s[i] * vol[i];
            wor2[cnt] = s[i] * wor[i];
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        for (int j = V; j >= vol2[i]; --j) {
            dp[j] = max(dp[j], dp[j - vol2[i]] + wor2[i]);
        }
    }
    printf("%d", dp[V]);
    return 0;
}