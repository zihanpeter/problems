// P4181 [USACO18JAN] Rental Service S
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m, r, c[N], ri[N], sum, prer[N];
struct node {
    int p, q;
} nds[N];
bool cmp(int x, int y) { return x > y; }
bool cmp2(node x, node y) { return x.p > y.p; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= m; ++i) cin >> nds[i].q >> nds[i].p;
    for (int i = 1; i <= r; ++i) cin >> ri[i];
    sort(c + 1, c + n + 1, cmp);
    sort(ri + 1, ri + r + 1, cmp);
    sort(nds + 1, nds + m + 1, cmp2);
    for (int i = 1; i <= r; ++i) prer[i] = prer[i - 1] + ri[i];
    
    int ti = 1, ans = 0, tans = 0;
    for (int i = 0; i <= n; ++i) {
        while (ti <= m && c[i]) {
            if (c[i] >= nds[ti].q) {
                tans += nds[ti].p * nds[ti].q;
                
                c[i] -= nds[ti].q;
                ++ti;
            } else {
                nds[ti].q -= c[i];
                
                tans += c[i] * nds[ti].p;
                
                c[i] = 0;
            }
        }
        ans = max(ans, tans + prer[min(r, n - i)]);
    }
    cout << ans;
    return 0;
}