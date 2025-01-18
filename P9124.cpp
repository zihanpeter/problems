// P9124 [USACO23FEB] Bakery S
#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int N = 1e2 + 5, INF = 0x3f3f3f3f3f3f3f3f;
int n, tc, tm, a[N], b[N], c[N], d[N];
/*
ai*(tc-t1)+bi*(tm-t2)<=ci
ai*tc-ai*t1+bi*tm-bi*t2<=ci
-ci+ai*tc+bi*tm<=ai*t1+bi*t2
di<=ai*t1+bi*t2
di<=ai*t1+bi*(mid-t1)
di-bi*mid<=(ai-bi)*t1
*/

bool check(int mid) {
    int maxf = 0, minf = INF;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[i] && d[i] - b[i] * mid > 0)
            return false;
        if (a[i] == b[i]) continue;
        double t = (d[i] - b[i] * mid) * 1.0 / (a[i] - b[i]);
        if (a[i] < b[i] && t < 1) 
            return false;
        else
            minf = min(minf, (int)ceil(t));
        if (a[i] > b[i] && t >= min(mid, tc)) 
            return false;
        else
            maxf = max(maxf, (int)t);
    }
    return maxf >= minf;
}

signed main() {
    // freopen("P9124.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> tc >> tm;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            d[i] = -c[i] + a[i] * tc + b[i] * tm;
            // cout << d[i] << ' ';
        }
        // cout << endl;
        int l = 0, r = tc + tm, ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            // cout << mid << ' ';
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
                // cout << 'y' << endl;
            } else {
                l = mid + 1;
                // cout << 'n' << endl;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}