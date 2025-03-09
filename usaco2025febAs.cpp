#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int n, a[N], cnt;
struct node {
    int x, pos;
} b[N];
bool cmp(node x, node y) {
    if (x.x == y.x) return x.pos < y.pos;
    return x.x > y.x;
}

int main() {
    // freopen("usaco2025febAs.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            b[i].x = a[i];
            b[i].pos = i;
        }
        sort(b + 1, b + n + 1, cmp);
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (b[i].pos < b[i - 1].pos) {
                if (cnt) break;
                cout << b[i].x << ' ';
                cnt = 1;
            } else cout << b[i].x << ' ';
        }
        cout << '\n';
    }
    return 0;
}