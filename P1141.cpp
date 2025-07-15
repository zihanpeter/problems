#include <iostream>
using namespace std;
const int N = 1e3 + 5;
int n, m, a[N][N], flag[N][N], cnt, ans[N * N], t;
char s[N];
int cx[] = {1, -1, 0, 0};
int cy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    ++t;
    flag[x][y] = cnt;
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        tx = cx[i] + x, ty = cy[i] + y;
        if (tx < 1 || tx > n || ty < 1 || ty > n || flag[tx][ty] || a[tx][ty] == a[x][y]) 
            continue;
        dfs(tx, ty);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < n; ++j) 
            a[i][j + 1] = s[j] - '0';
    }
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            if (!flag[i][j]) {
                ++cnt;
                t = 0;
                dfs(i, j);
                ans[cnt] = t;
            }
    int x, y;
    while (m--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", ans[flag[x][y]]);
    }
    return 0;
}