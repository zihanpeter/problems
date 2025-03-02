#include <iostream>
using namespace std;
const int N = 5e3 + 5;
int a[N][N], n, ans;
int cx[] = {1, -1, 0, 0}, cy[] = {0, 0, 1, -1};

bool check(int x, int y) {
    int cnt = 0;
    for (int k = 0; k < 4; ++k) {
        int tx = x + cx[k], ty = y + cy[k];
        if (a[tx][ty]) ++cnt;
    }
    if (cnt == 3) return true;
    return false;
}

void dfs(int x, int y) {
    ++ans;
    int ax, ay;
    for (int i = 0; i < 4; ++i) {
        int tx = x + cx[i], ty = y + cy[i];
        if (!a[tx][ty]) {
            ax = tx;
            ay = ty;
            break;
        }
    }
    a[ax][ay] = 1;
    if (check(ax, ay)) dfs(ax, ay);
    for (int i = 0; i < 4; ++i) {
        int tx = ax + cx[i], ty = ay + cy[i];
        if (a[tx][ty] && check(tx, ty)) 
            dfs(tx, ty);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        x += 2000;
        y += 2000;
        if (a[x][y]) {
            --ans;
        }
        a[x][y] = 1;
        if (check(x, y)) dfs(x, y);
        for (int i = 0; i < 4; ++i) {
            int tx = x + cx[i], ty = y + cy[i];
            if (a[tx][ty] && check(tx, ty)) dfs(tx, ty);
        }
        cout << ans << '\n';
    }
    return 0;
}