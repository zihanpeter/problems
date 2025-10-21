#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, tong[N << 1], f[N];
struct seg {
    int l, r;
} s[N];

bool cmp(seg x, seg y) { return x.l < y.l; }

int quick_pow(int x) {
    int ans = 1, a = 2;
    while (x) {
        if (x & 1) {
            ans = ans * a % MOD;
        }
        a = (a * a) % MOD;
        x >>= 1;
    }
    return ans;
}

main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &s[i].l, &s[i].r);
        ++tong[s[i].r];
    }
    for (int i = 1; i <= n << 1; ++i) tong[i] = tong[i - 1] + tong[i];
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        f[i] = ((2 * f[i - 1]) % MOD + quick_pow(tong[s[i].l]) % MOD) % MOD;
    }
    printf("%d", f[n]);
    return 0;
}