#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 3e6 + 5;
int n;
struct node {
    int x, y, id;
} cows[15][N];
int cnt[15], cnt_side;
int f[N];

bool operator < (const node &x, const node &y) {
    return x.x < y.x;
}

struct side
{
    int u, v, w;
} sides[N];

bool cmp(side x, side y) {
    return x.w < y.w;
}

int dis(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        cows[y][++cnt[y]] = node{x, y, i};
    }
    for (int i = 0; i < 10; ++i) {
        sort(cows[i] + 1, cows[i] + cnt[i] + 1);
    }

    for (int i = 0; i <= 10; ++i) {
        for (int j = 1; j <= cnt[i]; ++j) {
            for (int k = 0; k < 10; ++k) {
                int l = 1, r = cnt[k];
                node ans = cows[i][j];
                int ansi = 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (cows[k][mid] < ans) {
                        ans = cows[k][mid];
                        l = mid + 1;
                        ansi = mid;
                    } else r = mid - 1;
                }
                if (ansi - 1 > 0 && cows[k][ansi - 1].id > 0) sides[++cnt_side] = {cows[i][j].id, cows[k][ansi - 1].id, dis(cows[i][j].x, cows[i][j].y, cows[k][ansi - 1].x, cows[k][ansi - 1].y)};
                if (ansi + 1 <= cnt[k] && cows[k][ansi + 1].id > 0) sides[++cnt_side] = {cows[i][j].id, cows[k][ansi + 1].id, dis(cows[i][j].x, cows[i][j].y, cows[k][ansi + 1].x, cows[k][ansi + 1].y)};
                if (cows[k][ansi].id > 0) sides[++cnt_side] = {cows[i][j].id, cows[k][ansi].id, dis(cows[i][j].x, cows[i][j].y, cows[k][ansi].x, cows[k][ansi].y)};
            }
        }
    }

    sort(sides + 1, sides + cnt_side + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= cnt_side; ++i) {
        if (find(sides[i].u) != find(sides[i].v)) {
            f[find(sides[i].u)] = f[find(sides[i].v)];
            ans += sides[i].w;
        }
    }
    cout << ans;
    return 0;
}