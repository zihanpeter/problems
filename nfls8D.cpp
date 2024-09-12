#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m, l[N], r[N];
bool flag;

void debug() {
    int p;
    if (flag) {
        p = l[n + 1];
        for (int i = 1; i <= n; ++i) {
            cout << p << ' ';
            p = l[p];
        } 
    } else {
        p = r[0];
        for (int i = 1; i <= n; ++i) {
            cout << p << ' ';
            p = r[p];
        }
    }
    cout << endl;
}

int main() {
    scanf("%d%d", &n, &m);
    r[0] = 1;
    for (int i = 1; i <= n + 1; ++i) l[i] = i - 1, r[i] = i + 1;
    int opt, x, y;
    while (m--) {
        scanf("%d", &opt);
        if (opt != 4) {
            scanf("%d%d", &x, &y);
            if (flag) if (opt != 3) opt = 3 - opt;
        }
        if (opt == 1) { // 将x移到y的左边
            if (l[y] == x) continue;
            int lx = l[x], rx = r[x], ly = l[y];
            l[rx] = lx;
            r[lx] = rx;
            r[ly] = x;
            l[y] = x;
            l[x] = ly;
            r[x] = y;
        } else if (opt == 2) { // 将x移到y的右边
            if (r[y] == x) continue;
            int lx = l[x], rx = r[x], ry = r[y];
            l[rx] = lx;
            r[lx] = rx;
            r[y] = x;
            l[ry] = x;
            l[x] = y;
            r[x] = ry;
        } else if (opt == 3) { // 交换xy位置
            if (r[x] == y) {
                int lx = l[x], ry = r[y];
                l[x] = y, r[x] = ry;
                l[y] = lx, r[y] = x;
                r[lx] = y, l[ry] = x;
            } else if (l[x] == y) {
                int ly = l[y], rx = r[x];
                l[y] = x, r[y] = rx;
                l[x] = ly, r[x] = y;
                r[ly] = x, l[rx] = y;
            } else {
                int lx = l[x], rx = r[x], ly = l[y], ry = r[y];
                l[x] = ly, r[x] = ry;
                l[y] = lx, r[y] = rx;
                r[lx] = y, l[rx] = y;
                r[ly] = x, l[ry] = x;
            }
        } else if (opt == 4) flag = !flag;
        // debug();
    }
    long long ans = 0;
    int p;
    if (flag) {
        p = l[n + 1];
        for (int i = 1; i <= n; ++i) {
            if (i & 1) ans += p;
            p = l[p];
        } 
    } else {
        p = r[0];
        for (int i = 1; i <= n; ++i) {
            if (i & 1) ans += p;
            p = r[p];
        }
    }
    printf("%lld", ans);
    return 0;
}
