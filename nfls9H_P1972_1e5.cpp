#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5;
int n, m, a[N], s, tong[M], res, ans[N];
struct node {
    int l, r, num;
} nds[N];

bool cmp(node x, node y) {
    if ((x.l + s - 1) / s == (y.l + s - 1) / s) return x.r < y.r;
    return x.l < y.l;
}

void add(int x) { if (!tong[a[x]]++) ++res; }

void del(int x) { if (!(--tong[a[x]])) --res; }

int main() {
    scanf("%d", &n);
    s = sqrt(n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &nds[i].l, &nds[i].r);
        nds[i].num = i;
    }
    sort(nds + 1, nds + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        while (l < nds[i].l) del(l++);
        while (r < nds[i].r) add(++r);
        while (l > nds[i].l) add(--l);
        while (r > nds[i].r) del(r--);
        ans[nds[i].num] = res;
    }
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}