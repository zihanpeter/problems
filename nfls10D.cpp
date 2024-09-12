#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], dp[N], ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        dp[a[i] % m] = dp[m - a[i] % m] + 1;
        ans = max(ans, dp[a[i]]);
    }
    printf("%d", n - ans);
    return 0;
}