#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;
long long a[N], sumv[4 * N], lazy[4 * N];
void pushdown(int id, int l, int r) {
    if (lazy[id]) {
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        sumv[id << 1] += (mid - l + 1) * lazy[id];
        sumv[id << 1 | 1] += (r - mid) * lazy[id];
        lazy[id] = 0;
    }
}
void pushup(int id) {
    sumv[id] = sumv[id << 1] + sumv[id << 1 | 1];
}
void build(int id, int l, int r) {
    if (l == r) {
        sumv[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
}
void update(int id, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        lazy[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) 
        update(id << 1, l, mid, L, R, v);
    if (R > mid) 
        update(id << 1 | 1, mid + 1, r, L, R, v);
    pushup(id);
}
int query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return sumv[id];
    int mid = (l + r) >> 1, ans = 0; 
    if (L <= mid) 
        ans += query(id << 1, l, mid, L, R);
    if (R > mid) 
        ans += query(id << 1 | 1, mid + 1, r, L, R);
    return ans;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) 
        scanf("%lld", a + i);
    build(1, 1, n);
    int a, b, c;
    long long x;
    while (q--) {
        cin >> c;
        if (c == 1) {
            scanf("%d%d%lld", &a, &b, &x);
            update(1, 1, n, a, b, x);
        } else {
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(1, 1, n, a, b));
        }
    }
    return 0;
}