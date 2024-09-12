#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, a[25], s, sum, ans = INF, dp[25][1005][1005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		s += a[i]; sum += a[i];
	}
	s >>= 1; dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j <= s; ++j) 
			for (int k = 0; k <= s; ++k) 
				if (dp[i][j][k])
					dp[i + 1][j + a[i + 1]][k] = dp[i + 1][j][k + a[i + 1]] = dp[i + 1][j][k] = 1;
	for (int i = 0; i <= s; ++i) 
		for (int j = i; j <= s; ++j) 
			if (dp[n][i][j] && sum - i - j >= j) 
				ans = min(ans, sum - i - j);
	printf("%d", ans);
	return 0;
}