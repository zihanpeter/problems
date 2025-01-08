#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int N = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
int n, a[N], pre[N << 1], sum;

signed main() {
    int T;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        memset(pre, 0, sizeof(pre));
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
            sum += a[i];
        }
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = n + 1; i <= n << 1; ++i) {
            pre[i] = pre[i - 1] + a[i - n];
        }
        int maxf = -INF, l = (n >> 1) - 1;
        for (int i = n; i <= n + l; ++i) { // 枚举末尾的数字位置
            maxf = max(maxf, pre[i] - pre[i - l]);
        }
        printf("%lld %lld\n", sum - maxf, maxf);
    }
    return 0;
}