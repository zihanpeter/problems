#include <iostream>
using namespace std;

const int N = 1e2 + 5, INF = 0x3f3f3f3f;

int n, m, a[N][N];
double ans = -1e9;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i) {
        int maxf = -INF, minf = INF, sum = 0;
        for (int j = 1; j <= m; ++j) {
            sum += a[i][j];
            maxf = max(maxf, a[i][j]);
            minf = min(minf, a[i][j]);
        }
        double res = 1.0 * (sum - maxf - minf) / (m - 2);
        ans = max(ans, res);
    }
    printf("%.2f\n", ans);
    return 0;
}