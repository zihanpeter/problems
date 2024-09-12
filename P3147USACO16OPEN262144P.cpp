#include <iostream>
using namespace std;
const int N = 262145;
int n, dp[60][N], ans;
int main() {
    scanf("%d", &n);
    int t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        dp[t][i] = 1;
        ans = max(ans, t); 
    }
    for (int i = 1; i <= 58; ++i) 
        for (int j = 1; j <= n; ++j) {
        	if (!dp[i - 1][j] || !dp[i - 1][j + dp[i - 1][j]]) 
        		continue;
        	dp[i][j] = dp[i - 1][j] + dp[i - 1][j + dp[i - 1][j]];
        	if (dp[i][j]) 
        		ans = max(ans, i);
		} 
    printf("%d", ans);
    return 0;
}
