#include <iostream>
#include <cstring>
using namespace std;
int dp[105][105], a[105][105], n, m;
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) 
                cin >> a[i][j];
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) 
                dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i][j-1]);
        cout << dp[n][m] << endl;
    }
    return 0;
}