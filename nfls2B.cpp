#include <iostream>
#include <bitset>
using namespace std;
const int N = 1e6 + 5;
bitset<1000005> dp;
int n, m, w[N], cnt;
int main() {
    scanf("%d%d", &n, &m);
    int v, s;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &v, &s);
        for (int t = 1; t <= s; t <<= 1) {
            w[++cnt] = t * v;
            s -= t;
        }
        if (s) w[++cnt] = s * v;
    }
    for (int i = 1; i <= cnt; ++i) dp |= (dp << w[i]);
    for (int i = 1; i <= m; ++i) cout << dp[i];
    return 0;
}