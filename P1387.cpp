#include <iostream>
using namespace std;
const int N = 1e2 + 5;
int n, m, a[N][N], f[N][N], ans;


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }
    printf("%d", ans);
    return 0;
}