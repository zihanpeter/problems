#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], cx[N], cy[N], sum[N];
int lowbit(int x) {
    return x & -x;
}
void update(int *c, int x, int v) {
    while (x <= 100000) {
        c[x] += v;
        x += lowbit(x);
    }
}
int query(int *c, int x) {
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int main() {
    cin >> n;
    int maxf = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxf = max(maxf, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] = query(cx, a[i] - 1);
        update(cx, a[i], 1);
    }
    long long ans = 0;
    for (int i = n; i >= 1; --i) {
        ans += 1ll * (query(cy, maxf) - query(cy, a[i])) * sum[i];
        update(cy, a[i], 1);
    }
    cout << ans << endl;
    return 0;
}