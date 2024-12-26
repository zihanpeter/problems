#include <iostream>
using namespace std;
const int N = 2e3 + 5, INF = 0x3f3f3f3f;
int n, m, a[N][N], f[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) 
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= m; ++i) {
			if (i == 1) f[i][j] = min(f[i][j - 1], f[m][j - 1]) + a[i][j];
			else f[i][j] = min(f[i][j - 1], f[i - 1][j - 1]) + a[i][j];
		}
	}
	int ans = INF;
	for (int i = 1; i <= m; ++i) ans = min(ans, f[i][n]);
	printf("%d", ans);
    return 0;
}
