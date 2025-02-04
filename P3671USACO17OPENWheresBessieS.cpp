#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 25;
char s[N][N], col;
struct node {
    int x1, y1, x2, y2, area;
} nds[1000005];
int n, ans, a, b, c, d, tong[128];
bool vis[N][N], tans[1000005];
int cx[] = {0, 0, 1, -1};
int cy[] = {1, -1, 0, 0};
bool cmp(node x, node y) { return x.area > y.area; }

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int tx = x + cx[i], ty = y + cy[i];
        if (tx < a || tx > c || ty < b || ty > d || vis[tx][ty] || s[tx][ty] != col) 
            continue;
        vis[tx][ty] = true;
        dfs(tx, ty);
    }
}

void check(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return;
    memset(vis, 0, sizeof(vis));
    memset(tong, 0, sizeof(tong));
    int cnt_diff = 0;
    col = ' ';
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (!vis[i][j]) {
                a = x1, b = y1, c = x2, d = y2;
                if (!tong[s[i][j]]) ++cnt_diff;
                ++tong[s[i][j]];
                if (cnt_diff > 2) return;
                col = s[i][j];
                vis[i][j] = true;
                dfs(i, j);
            }
        }
    }
    if (cnt_diff == 2) {
        int cnt1 = 0;
        for (int i = 0; i < 128; ++i) if (tong[i] == 1) ++cnt1;
        if (cnt1 == 1) 
            nds[++ans] = node{x1, y1, x2, y2, (x2 - x1 + 1) * (y2 - y1 + 1)};
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            for (int u = 0; u < n; ++u) 
                for (int v = 0; v < n; ++v) 
                    check(i, j, u, v);
    sort(nds + 1, nds + ans + 1, cmp);
    int realans = 0;
    for (int i = 1; i <= ans; ++i) {
        // cout << nds[i].x1 + 1 << ' '  << nds[i].y1 + 1 << ' ' << nds[i].x2 + 1 << ' ' << nds[i].y2 + 1 << ' ' << nds[i].area << endl;
        bool flag = true;
        for (int j = 1; j < i; ++j) {
            if (tans[j]) continue;
            if (nds[j].x1 <= nds[i].x1 && 
                nds[j].x2 >= nds[i].x2 &&
                nds[j].y1 <= nds[i].y1 &&
                nds[j].y2 >= nds[i].y2) {
                    tans[i] = true;
                    flag = false;
                    break;
                }
        }
        if (flag) ++realans;
    }
    cout << realans;
    return 0;
}