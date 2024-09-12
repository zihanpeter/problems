#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, a[N], v[N];
int ans, v2[N];
int maxf = -0x3f3f3f3f;
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        maxf = max(maxf, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ++v[a[i]];
        v2[a[i]] += a[i];
    }
    for (int i = 1; i <= 1e6; ++i) {
        v[i] = v[i - 1] + v[i];
        v2[i] = v2[i - 1] + v2[i];
    }
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        int sum = 0;
        for (int j = 0; (j + 1) * a[i] < maxf + a[i]; ++j) {
            cnt = v[(j + 1) * a[i] - 1] - v[j * a[i]];
            sum = v2[(j + 1) * a[i] - 1] - v2[j * a[i]];
            ans += sum - 1ll * j * cnt * a[i];
        }
    }
    printf("%lld", ans);
    return 0;
}