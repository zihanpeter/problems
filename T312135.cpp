#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, a[N], f[N], l[N], r[N], ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    f[0] = l[0] = -INF;
    for (int i = 1; i <= n; ++i) {
        f[i] = max(f[i - 1] + a[i], a[i]);
        l[i] = max(l[i - 1], f[i]);
    }
    memset(f, 0, sizeof(f));
    f[n + 1] = r[n + 1] = -INF;
    for (int i = n; i >= 1; --i) {
        f[i] = max(f[i + 1] + a[i], a[i]);
        r[i] = max(r[i + 1], f[i]);
    }
    ans = -INF;
    for (int i = 1; i < n; ++i) ans = max(ans, l[i] + r[i + 1]);
    printf("%d", ans);
    return 0;
}
