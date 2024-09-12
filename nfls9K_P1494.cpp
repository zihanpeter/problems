#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e4 + 5, sz = 300;
int n, m, c[N], ans1[N], ans2[N], cnt[N], res;
struct node {
    int l, r, num;
} nds[N];
bool cmp(node x, node y) {
    if (x.l / sz == y.l / sz) return x.r < y.r;
    return x.l < y.l;
}
void add(int x) { res += cnt[c[x]]++; }
void del(int x) { res -= --cnt[c[x]]; }
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", c + i);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld%lld", &nds[i].l, &nds[i].r);
        nds[i].num = i;
    }
    sort(nds + 1, nds + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        if (nds[i].l == nds[i].r) {
            ans1[nds[i].num] = 0, ans2[nds[i].num] = 1;
            continue;
        }
        while (nds[i].l < l) add(--l);
        while (nds[i].l > l) del(l++);
        while (nds[i].r < r) del(r--);
        while (nds[i].r > r) add(++r);
        ans1[nds[i].num] = res;
        ans2[nds[i].num] = (r - l + 1) * (r - l) / 2;
        int g = __gcd(ans1[nds[i].num], ans2[nds[i].num]);
        ans1[nds[i].num] /= g, ans2[nds[i].num] /= g;
    }
    for (int i = 1; i <= m; ++i) printf("%lld/%lld\n", ans1[i], ans2[i]);
    return 0;
}