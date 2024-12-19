// Gold Mining
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e6 + 5, INF = 0x3f3f3f3f;
int n, m;
struct node {
    int x, y, t;
} nds[N];

bool cmp(node x, node y) {
    if (x.x == y.x) {
        if (x.t == y.t) {
            return x.y < y.y;
        }
        return x.t > y.t;
    }
    return x.x < y.x;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &nds[i].x, &nds[i].y);
        nds[i].t = 1;
    }
    for (int i = n + 1; i <= n + m; ++i) {
        scanf("%d%d", &nds[i].x, &nds[i].y);
        nds[i].t = 2;
    }
    sort(nds + 1, nds + n + m + 1, cmp);

    int mxh = -INF, act = -INF, ans = 0, ams = 0;
    for (int i = 1; i <= n + m; ++i) {
        if (nds[i].t == 1) { // gold
            if (nds[i].y > mxh) {
                ++ams;
                continue;
            }
            if (nds[i].y > act) {
                ++ans;
                act = mxh;
            }
        } else { // machine
            mxh = max(mxh, nds[i].y);
        }
    }
    if (ams) {
        printf("%d %d", -1, ams);
    } else {
        printf("%d", ans);
    }
    return 0;
}