// P3131 [USACO16JAN] Subsequences Summing to Sevens S
#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e4 + 5;
int n, a[N], pre[N], fp[10], lp[10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) pre[i] = (pre[i - 1] + a[i]) % 7;
    memset(fp, 0x3f, sizeof(fp));
    for (int i = 1; i <= n; ++i) {
        fp[pre[i]] = min(i, fp[pre[i]]);
        lp[pre[i]] = max(i, lp[pre[i]]);
    }
    int ans = 0;
    fp[0] = 0;
    for (int i = 0; i < 7; ++i) {
        if (fp[i] == 0x3f3f3f3f) continue;
        ans = max(ans, lp[i] - fp[i]);
    }
    printf("%d", ans);
    return 0;
}