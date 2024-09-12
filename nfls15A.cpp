#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, cnt[55][55], maxf = -INF, mi, mj, ans;
int cx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int cy[] = {0, 0, 1, -1, -1, 1, -1, 1};
bool tong[55][55][55][55];
string s[55];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i]; s[i] = " " + s[i];
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) 
        if (s[i][j] == '.') 
            for (int k = 0; k < 8; ++k) {
                int tx = i + cx[k], ty = j + cy[k];
                if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
                if (s[tx][ty] == 'o') 
                    if (++cnt[i][j] > maxf) maxf = cnt[i][j], mi = i, mj = j;
            }
    if (maxf ^ -INF) s[mi][mj] = 'o';
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) 
        if (s[i][j] == 'o') 
            for (int k = 0; k < 8; ++k) {
                int tx = i + cx[k], ty = j + cy[k];
                if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
                if (s[tx][ty] == 'o' && !tong[i][j][tx][ty]) {
                    ++ans;
                    tong[i][j][tx][ty] = tong[tx][ty][i][j] = true;
                }
            }
    cout << ans;
    return 0;
}