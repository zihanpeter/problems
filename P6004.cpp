// P6004 [USACO20JAN] Wormhole Sort S
#include <iostream>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, m, p[N], f[N];
struct node {
    int a, b, w;
} nds[N];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx ^ fy) f[fx] = fy;
}

bool check(int mid) {
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) 
        if (nds[i].w >= mid) merge(nds[i].a, nds[i].b);
    int fa = -1;
    for (int i = 1; i <= n; ++i) 
        if (p[i] ^ i) {
            if ((~fa) && (fa ^ find(i))) 
                return false;
            if (!(~fa)) fa = find(i);
        }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= m; ++i) cin >> nds[i].a >> nds[i].b >> nds[i].w;
    int l = 0, r = INF, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    for (int i = 1; i <= n; ++i) 
        if (p[i] ^ i) {
            cout << ans;
            exit(0);
        }
    cout << -1;
    return 0;
}