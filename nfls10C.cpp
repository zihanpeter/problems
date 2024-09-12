#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, ans, a[N << 1], cnt, cha[N << 1], to[N];
struct node {
    int l, r;
} s[N];
int main() {
    scanf("%d", &n);
    char c;
    int x, pos = 0;
    for (int i = 1; i <= n; ++i) {
        getchar();
        scanf("%d %c", &x, &c);
        if (c == 'L') {
            s[i].l = pos - x; s[i].r = pos;
            a[++cnt] = s[i].l; a[++cnt] = s[i].r;
            pos -= x;
        } else {
            s[i].l = pos; s[i].r = pos + x;
            a[++cnt] = s[i].l; a[++cnt] = s[i].r;
            pos += x;
        }
    }
    sort(a + 1, a + cnt + 1);
    int m = unique(a + 1, a + cnt + 1) - a - 1, y;
    for (int i = 1; i <= n; ++i) {
        x = lower_bound(a + 1, a + m + 1, s[i].l) - a;
        y = lower_bound(a + 1, a + m + 1, s[i].r) - a;
        to[x] = s[i].l; to[y] = s[i].r;
        s[i].l = x; s[i].r = y;
    }
    for (int i = 1; i <= n; ++i) ++cha[s[i].l], --cha[s[i].r];
    for (int i = 1; i <= m; ++i) {
        cha[i] += cha[i - 1];
        if (cha[i] >= 2) {
            ans += to[i + 1] - to[i];
        }
    }
    printf("%d", ans);
    return 0;
}