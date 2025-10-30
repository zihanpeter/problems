#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e3 + 5;
int h, g, hx[N], hy[N], gx[N], gy[N], dp[N][N][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> g;
    for (int i = 1; i <= h; ++i) cin >> hx[i] >> hy[i];
    for (int i = 1; i <= g; ++i) cin >> gx[i] >> gy[i];

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= g; ++j) {
            dp[i][j][0] = dp[i][j][1] = 0x3f3f3f3f;
        }
    }

    dp[1][0][0] = 0;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= g; ++j) {
            dp[i][j][0] = min(dp[i][j][0], 
                (int) min(
                    dp[i - 1][j][1] + pow(hx[i] - gx[j], 2) + pow(hy[i] - gy[j], 2), 
                    dp[i - 1][j][0] + pow(hx[i - 1] - hx[i], 2) + pow(hy[i - 1] - hy[i], 2)
                )
            );
            
            dp[i][j][1] = min(dp[i][j][1], 
                (int) min(
                    dp[i][j - 1][0] + pow()
                )
            )
        }
    }
    return 0;
}