#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, m, a[N], b[N];

long long f[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= m; ++i) scanf("%d", b + i);
    // for (int i = 2; i <= m; ++i) f[i] = f[i - 1] + abs(b[i] - b[i - 1]);
    // for (int i = 2; i <= n; ++i) 
    //     for (int j = 1; j <= m; ++j) 
    //         if (j == 1) f[j] = f[j] + abs(a[i] - a[i - 1]);
    //         else f[j] = min(f[j - 1] + abs(b[j] - b[j - 1]), f[j] + abs(a[i] - a[i - 1]));
    // printf("%d", f[m]);
    long long ans = 0;
    for (int i = 1; i < n; ++i) ans += abs(a[i] - a[i + 1]);
    for (int i = 1; i < m; ++i) ans += abs(b[i] - b[i + 1]);
    printf("%lld", ans);
    return 0;
}