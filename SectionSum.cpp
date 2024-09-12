#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n, a[N], q;
ll tree[N << 2], lazy[N << 2];
void pushUp(int id) {
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushUp(id);
}
void pushDown(int id, int l, int r) {
    if (lazy[id]) {
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        tree[id << 1] += (mid - l + 1) * lazy[id];
        tree[id << 1 | 1] += (r - mid) * lazy[id];
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        lazy[id] += v;
        tree[id] += v * (r - l + 1);
        return;
    }
    pushDown(id, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) 
        update(id << 1, l, mid, L, R, v);
    if (R > mid) 
        update(id << 1 | 1, mid + 1, r, L, R, v);
    pushUp(id);
}
ll query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree[id];
    pushDown(id, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid) 
        ans += query(id << 1, l, mid, L, R);
    if (R > mid) 
        ans += query(id << 1 | 1, mid + 1, r, L, R);
    return ans; 
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i);
    build(1, 1, n);
    scanf("%d", &q);
    int mode, l, r, d;
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &mode);
        if (mode == 1) {
            scanf("%d%d%d", &l, &r, &d);
            update(1, 1, n, l, r, d);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}