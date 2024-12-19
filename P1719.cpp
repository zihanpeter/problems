#include <iostream>
using namespace std;
const int N = 120 + 5, INF = 0x3f3f3f3f;
int n, a[N][N], pre[N][N], ans = -INF;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            pre[i][j] = pre[i - 1][j] - pre[i - 1][j - 1] + pre[i][j - 1] + a[i][j];
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            for (int x = i; x <= n; ++x) 
                for (int y = j; y <= n; ++y) {
                    ans = max(ans, pre[x][y] - pre[i - 1][y] - pre[x][j - 1] + pre[i - 1][j - 1]);
                }
    printf("%d", ans);
    return 0;
}