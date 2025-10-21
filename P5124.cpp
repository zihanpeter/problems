#include <iostream>
using namespace std;
const int N = 1e4 + 5, INF = 0x3f3f3f3f;
int n, k, a[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        int maxf = -INF;
        for (int j = 0; j < k && i - j >= 1; ++j) {
            maxf = max(maxf, a[i - j]);
            dp[i] = max(dp[i], dp[i - j - 1] + maxf * (j + 1));
        }
    }

    cout << dp[n];
    return 0;
}