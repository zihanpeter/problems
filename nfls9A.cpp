#include <iostream>
using namespace std;
const int N = 5e4 + 5;

int n, m, a[N], dp[N][305];

int main() {
	scanf("%d%d", &n, &m);
	int sq = sqrt(n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = n; i >= 1; --i) 
		for (int j = 1; j <= 300; ++j)
			dp[i][j] = dp[i + j][j] + a[i];
	int x, t;
	while (m--) {
		scanf("%d%d", &x, &t);
		if (t <= 300) {
			printf("%d\n", dp[x][t]);
		} else {
			int ans = 0;
			for (int i = x; i <= n; i += t) ans += a[i];
			printf("%d\n", ans);
		}
	}
	return 0;
}