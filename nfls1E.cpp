#include <iostream>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, k, f[15][N], ans[15];

int main() {
	scanf("%d%d", &n, &k);
	ans[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			f[i][j] = ans[i - 1];
			for (int p = j * 2; p <= k; p += j) {
				f[i][j] = (f[i][j] - f[i - 1][p] + MOD) % MOD;
			}
		}
		for (int j = 1; j <= k; ++j) {
			ans[i] = (ans[i] + f[i][j]) % MOD;
		}
	}
	printf("%d", ans[n]);
	return 0;
}
