#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int n, m, a[N], tong[N], s = 500, blo[500], ans[N];
struct node {
    int l, r, num;
} nds[N];
bool cmp(node x, node y) {
    if (x.l / s == y.l / s) return x.r < y.r;
    return x.l < y.l;
}

void add(int x) {
    if (!tong[a[x]]++) ++blo[a[x] / s];
}

void del(int x) {
    if (!(--tong[a[x]])) --blo[a[x] / s];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] > n) a[i] = n + 1;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &nds[i].l, &nds[i].r);
        nds[i].num = i;
    }
    sort(nds + 1, nds + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        while (nds[i].l > l) del(l++);
        while (nds[i].l < l) add(--l);
        while (nds[i].r > r) add(++r);
        while (nds[i].r < r) del(r--);
        for (int j = 0; j <= n / s; ++j) {
            if (blo[j] == s) continue;
            for (int k = j * s; k < (j + 1) * s; ++k) {
                if (!tong[k]) {
                    ans[nds[i].num] = k;
                    break;
                }
            }
            break;
        }
    }
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}