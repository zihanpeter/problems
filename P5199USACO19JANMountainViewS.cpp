#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n;
struct node {
    int x, y, l, r;
} nds[N];
bool cmp(node x, node y) {
    if (x.l == y.l) return x.r > y.r;
    return x.l < y.l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nds[i].x >> nds[i].y;
        nds[i].l = nds[i].x - nds[i].y;
        nds[i].r = nds[i].x + nds[i].y;
    }
    sort(nds + 1, nds + n + 1, cmp);
    int maxr = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (nds[i].r > maxr) {
            maxr = nds[i].r;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}