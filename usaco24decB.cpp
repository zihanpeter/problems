#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 3e5 + 5;
int n, k, a[N], b[N], tree[N << 2], lazy[N << 2];
struct node {
    int l, r, t;
} nds[N];

bool cmp(node x, node y) {
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}

void deal() {
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b - 1;
    for (int i = 1; i <= k; ++i) {
        nds[i].l = lower_bound(b + 1, b + n + 1, nds[i].l) - b - 1;
        nds[i].r = lower_bound(b + 1, b + n + 1, nds[i].r) - b - 1;
    }
}

void push_down(int id, int l, int r) {
    if (lazy[id]) {
        int mid = l + r >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        tree[id << 1] += lazy[id] * (mid - l + 1);
        tree[id << 1 | 1] += lazy[id] * (r - mid);
        lazy[id] = 0;
    }
}

void push_up(int id) {
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[id];
    push_down(id, l, r);
    int mid = l + r >> 1, ans = 0;
    if (L <= mid) ans += query(id << 1, l, mid, L, R);
    if (R > mid) ans += query(id << 1 | 1, mid + 1, r, L, R);
    return ans;
}

void update(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        lazy[id] += 1;
        tree[id] += r - l + 1;
        return;
    }
    int mid = l + r >> 1;
    push_down(id, l, r);
    if (L <= mid) update(id << 1, l, mid, L, R);
    if (R > mid) update(id << 1 | 1, mid + 1, r, L, R);
    push_up(id);
}

int main() {
    freopen("usaco24decB.out", "w", stdout);
    freopen("usaco24decB.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        for (int i = 1; i <= k; ++i) scanf("%d%d%d", &nds[i].l, &nds[i].r, &nds[i].t); // 这个也需要离散化？
        // 离散化？
        deal();
        sort(nds + 1, nds + n + 1, cmp);
        for (int i = 1; i <= k; ++i) {
            int res = query(1, 1, n, nds[i].l, nds[i].r);
            cout << "-------" << endl;
            int c = nds[i].t - res;
            if (c < nds[i].r - nds[i - 1].r) {
                update(1, 1, n, nds[i].r, nds[i].r - c + 1);
            } else {
                update(1, 1, n, nds[i].r, nds[i - 1].r + 1);
                int cc = c - (nds[i].r - nds[i - 1].r - 1);
                update(1, 1, n, nds[i - 1].r - nds[i - 1].t + 1, 
                            nds[i - 1].r - nds[i - 1].t + 1 - cc + 1);
            }
        }
        printf("%d\n", n - query(1, 1, n, 1, n));
    }
    return 0;
}