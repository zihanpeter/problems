#include <bits/stdc++.h>
using namespace std;
int n, m, c[55];
bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i] >= x) continue;
        cnt += x - c[i];
        if (cnt > m || cnt > x) return false;
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
    return 0;
}
