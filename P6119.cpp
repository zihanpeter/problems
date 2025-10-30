#include <iostream>
using namespace std;
const int N = 1e3 + 5;
int n, a[N], b[N], dp[N][N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(
                max(
                    dp[i][j], 
                    dp[i - 1][j - 1] + (int) (abs(a[i] - b[j]) <= 4)
                ), 
                max(
                    dp[i - 1][j], 
                    dp[i][j - 1]
                )
            );
        }
    }

    cout << dp[n][n];
    return 0;
}