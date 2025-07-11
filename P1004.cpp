#include <iostream>
using namespace std;
const int N = 15;
int n, a[N][N], dp[N][N][N][N];

int main() {
    scanf("%d", &n);
    int x, y, z;
    while (true) {
        scanf("%d%d%d", &x, &y, &z);
        if (!x && !y && !z) break;
        a[x][y] = z;
    }
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            for (int x = 1; x <= n; ++x) 
                for (int y = 1; y <= n; ++y) 
                    if (i == x && j == y) 
                        dp[i][j][x][y] = max(dp[i - 1][j][x][y - 1], dp[i][j - 1][x - 1][y]) + a[i][j];
                    else 
                        dp[i][j][x][y] = max(max(dp[i - 1][j][x][y - 1], dp[i][j - 1][x - 1][y]), max(dp[i - 1][j][x - 1][y], dp[i][j - 1][x][y - 1])) + a[i][j] + a[x][y];
    printf("%d", dp[n][n][n][n]);
    return 0;
}