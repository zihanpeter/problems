#include <iostream>
#include <queue>
using namespace std;
int n, m, t;
char c[30][30];
int qx, qy, ans = -1;
bool vis[1 << 10][30][30];
int cx[] = {1, -1, 0, 0};
int cy[] = {0, 0, 1, -1};
struct node {
    int x, y, step, mode;
};
queue<node> q;
void bfs() {
    q.push(node{qx, qy, 0, 0});
    vis[0][qx][qy] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        int mode = q.front().mode;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + cx[i];
            int ty = y + cy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || c[tx][ty] == '#') 
                continue;
            if (c[tx][ty] == '$') {
                ans = step + 1;
                if (ans > t) ans = -1;
                return;
            }
            if (c[tx][ty] >= 'A' && c[tx][ty] <= 'J') {
                if (vis[mode][tx][ty]) continue;
                vis[mode][tx][ty] = true;
                int t = c[tx][ty] - 'A';
                if ((mode >> t) & 1) {
                    q.push(node{tx, ty, step + 1, mode});
                }
            } else if (c[tx][ty] >= 'a' && c[tx][ty] <= 'j') {
                int t = c[tx][ty] - 'a';
                if (vis[mode | (1 << t)][tx][ty]) continue;
                vis[mode | (1 << t)][tx][ty] = true;
                q.push(node{tx, ty, step + 1, mode | (1 << t)});
            } else {
                if (vis[mode][tx][ty]) continue;
                vis[mode][tx][ty] = true;
                q.push(node{tx, ty, step + 1, mode});
            }
        }
    }
}
int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            cin >> c[i][j];
            if (c[i][j] == '@') {
                qx = i;
                qy = j;
            }
        }
    bfs();
    cout << ans << endl;
    return 0;
}