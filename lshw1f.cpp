#include <iostream>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, q, s, t, a[N], cha[N], ans;
signed main() {
    scanf("%lld%lld%lld%lld", &n, &q, &s, &t);
    for (int i = 1; i <= n + 1; ++i) {
        scanf("%lld", a + i);
        cha[i] = a[i] - a[i - 1];
        ans += cha[i] < 0 ? -cha[i] * t : -cha[i] * s;
    }
    for (int i = 1; i <= q; ++i) {
        int l, r, x;
        scanf("%lld%lld%lld", &l, &r, &x);
        ++l; ++r;
        ans -= cha[l] < 0 ? -cha[l] * t : -cha[l] * s;
        if (r <= n) ans -= cha[r + 1] < 0 ? -cha[r + 1] * t : -cha[r + 1] * s;
        cha[l] += x;
        cha[r + 1] -= x;
        ans += cha[l] < 0 ? -cha[l] * t : -cha[l] * s;
        if (r <= n) ans += cha[r + 1] < 0 ? -cha[r + 1] * t : -cha[r + 1] * s;
        printf("%lld\n", ans);
    }
    return 0;
}