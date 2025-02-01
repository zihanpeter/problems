#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m;
struct node {
    int a, b;
} nds[N];
bool cmp(node x, node y) { return x.a < y.a; }

bool check(int x) {
    int lp = nds[1].a, li = 1;
    for (int i = 2; i <= n; ++i) {
        while (lp + x > nds[li].b) {
            ++li;
            if (li > m) return false;
        }
        lp = max(nds[li].a, lp + x);
    }
    return true;
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> nds[i].a >> nds[i].b;
    }
    sort(nds + 1, nds + m + 1, cmp);
    int l = 1, r = 1e18, ans = 1;
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