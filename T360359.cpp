#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, a[N], sum, t[N];
vector<int> g[N];
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    for (int i = 1; i <= n; ++i) sum = (sum + a[i] * i % MOD * (n - i + 1) % MOD) % MOD;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        g[y].push_back(x);
        if (x <= y) ++t[y];
    }
    for (int y = 1; y <= n; ++y) {
        for (int j = 0; j < g[y].size(); ++j) {
            int x = g[y][j];
            if (x < y) sum = (sum - (n - y + 1) * a[y] % MOD + MOD) % MOD;
            else if (x > y) sum = (sum - (y - t[y]) * a[y] % MOD + MOD) % MOD;
            else sum = (sum - a[y] * (n - t[y] + 1) % MOD + MOD) % MOD;   
        }
    }
    printf("%lld", sum);
    return 0;
}
