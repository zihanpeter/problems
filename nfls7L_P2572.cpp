#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], lazy[N << 2], lazy2[N << 2];

struct node {
    int len, sum;
    int lx[2], rx[2], mx[2];
    void init() {
        lx[0] = lx[1] = 0;
        rx[0] = rx[1] = 0;
        mx[0] = mx[1] = 0;
    }
    void all(int x) {
        lx[x] = rx[x] = mx[x] = len;
    }
} tree[N << 2];

node push_up(node x, node y) {
    node z;
    z.init();
    z.len = x.len + y.len;
    z.sum = x.sum + y.sum;
    for (int i = 0; i <= 1; ++i) {
        z.mx[i] = max(max(x.mx[i], y.mx[i]), x.rx[i] + y.lx[i]);
        z.lx[i] = x.lx[i];
        z.rx[i] = y.rx[i];
        if (x.lx[i] == x.len) z.lx[i] += y.lx[i];
        if (y.rx[i] == y.len) z.rx[i] += x.rx[i];
    }
    return z;
}

void build(int id, int l, int r) {
    tree[id].len = r - l + 1;
    if (l == r) {
        if (a[l]) tree[id].lx[1] = tree[id].rx[1] = tree[id].mx[1] = tree[id].sum = 1;
        else tree[id].lx[0] = tree[id].rx[0] = tree[id].mx[0] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    tree[id] = push_up(tree[id << 1], tree[id << 1 | 1]);
}

void swapper(int id) {
    tree[id].sum = tree[id].len - tree[id].sum;
    swap(tree[id].lx[0], tree[id].lx[1]);
    swap(tree[id].rx[0], tree[id].rx[1]);
    swap(tree[id].mx[0], tree[id].mx[1]);
}

void push_down(int id) {
    if (~lazy2[id]) {
        lazy2[id << 1] = lazy2[id << 1 | 1] = lazy2[id];
        lazy[id] = lazy[id << 1] = lazy[id << 1 | 1] = 0;
        tree[id << 1].sum = tree[id << 1].len * lazy2[id];
        tree[id << 1 | 1].sum = tree[id << 1 | 1].len * lazy2[id];
        tree[id << 1].init(), tree[id << 1 | 1].init();
        tree[id << 1].all(lazy2[id]), tree[id << 1 | 1].all(lazy2[id]);
        lazy2[id] = -1;
    }
    if (lazy[id]) {
        if (~lazy2[id << 1]) lazy2[id << 1] ^= 1;
        else lazy[id << 1] ^= 1;
        if (~lazy2[id << 1 | 1]) lazy2[id << 1 | 1] ^= 1;
        else lazy[id << 1 | 1] ^= 1;
        swapper(id << 1), swapper(id << 1 | 1);
        lazy[id] = 0;
    }
}

void modify(int id, int l, int r, int L, int R, int mode) {
    push_down(id);
    if (L <= l && r <= R) {
        if (mode == 2) {
            lazy[id] ^= 1;
            swapper(id);
        } else {
            lazy2[id] = mode;
            tree[id].sum = tree[id].len * mode;
            tree[id].init();
            tree[id].all(mode);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) modify(id << 1, l, mid, L, R, mode);
    if (R > mid) modify(id << 1 | 1, mid + 1, r, L, R, mode);
    tree[id] = push_up(tree[id << 1], tree[id << 1 | 1]);
}

node query(int id, int l, int r, int L, int R) {
    push_down(id);
    if (L <= l && r <= R) return tree[id];
    int mid = (l + r) >> 1;
    if (R <= mid) return query(id << 1, l, mid, L, R);
    if (L > mid) return query(id << 1 | 1, mid + 1, r, L, R);
    return push_up(query(id << 1, l, mid, L, R), query(id << 1 | 1, mid + 1, r, L, R));
}

int ask(int id, int l, int r, int L, int R) {
    push_down(id);
    if (L <= l && r <= R) return tree[id].sum;
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid) ans += ask(id << 1, l, mid, L, R);
    if (R > mid) ans += ask(id << 1 | 1, mid + 1, r, L, R);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    build(1, 1, n);
    memset(lazy2, 0xff, sizeof(lazy2));
    int x, l, r;
    while (m--) {
        scanf("%d%d%d", &x, &l, &r);
        ++l, ++r;
        if (x == 0) modify(1, 1, n, l, r, 0);
        else if (x == 1) modify(1, 1, n, l, r, 1);
        else if (x == 2) modify(1, 1, n, l, r, 2);
        else if (x == 3) printf("%d\n", ask(1, 1, n, l, r));
        else if (x == 4) printf("%d\n", query(1, 1, n, l, r).mx[1]);
    }
    return 0;
}