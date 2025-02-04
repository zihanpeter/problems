#include <iostream>
using namespace std;
const int N = 1e2 + 5;
int n, k, r, cnt, blo, vcnt[N * N];
int cx[] = {0, 0, -1, 1};
int cy[] = {-1, 1, 0, 0};
bool vis[N][N], road[N][N][4], cow[N][N];

int checkDirect(int x1, int y1, int x2, int y2) {
    for (int i = 0; i < 4; ++i) {
        int tx = x1 + cx[i], ty = y1 + cy[i];
        if (tx == x2 && ty == y2) return i;
    }
}

void dfs(int x, int y) {
    if (cow[x][y]) ++cnt;
    for (int i = 0; i < 4; ++i) {
        if (road[x][y][i]) continue;
        int tx = x + cx[i], ty = y + cy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > n || vis[tx][ty]) 
            continue;
        vis[tx][ty] = true;
        dfs(tx, ty);
    }
}

int main() {
    cin >> n >> k >> r;
    for (int i = 1; i <= r; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        road[a][b][checkDirect(a, b, c, d)] = true;
        road[c][d][checkDirect(c, d, a, b)] = true;
    }
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        cow[x][y] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!vis[i][j]) {
                vis[i][j] = true;
                cnt = 0;
                dfs(i, j);
                vcnt[++blo] = cnt;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= blo; ++i) 
        for (int j = i + 1; j <= blo; ++j) 
            ans += vcnt[i] * vcnt[j];
    cout << ans;
    return 0;
}