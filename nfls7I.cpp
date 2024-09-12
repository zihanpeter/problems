#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, a[N];
struct node {
    ll x;
    int m;
} tree[N << 2], lazy[N << 2];
void push_up(int id) {
    tree[id].x = tree[id << 1].x + tree[id << 1 | 1].x;
    tree[id].m = tree[id << 1].m & tree[id << 1 | 1].m;
}
void build(int id, int l, int r) {
    if (l == r) {
        tree[id].x = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    push_up(id);
}
ll query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[id].x;
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid) ans += query(id << 1, l, mid, L, R);
    if (R > mid) ans += query(id << 1 | 1, mid + 1, r, L, R);
    return ans;
}
void modify(int id, int l, int r, int L, int R) {
    if (tree[id].m) return;
    if (l == r) {
        tree[id].x = sqrt(tree[id].x);
        if (tree[id].x <= 1) tree[id].m = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) modify(id << 1, l, mid, L, R);
    if (R > mid) modify(id << 1 | 1, mid + 1, r, L, R);
    push_up(id);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    build(1, 1, n);
    scanf("%d", &m);
    int x, l, r;
    while (m--) {
        scanf("%d%d%d", &x, &l, &r);
        if (x == 1) {
            printf("%lld\n", query(1, 1, n, l, r));
        } else {
            modify(1, 1, n, l, r);
        }
    }
    return 0;
}