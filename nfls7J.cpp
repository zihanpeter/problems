#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], lazy[N << 2];

struct node {
    int len; // 区间长度
    int lx[2], rx[2], mx[2]; // 存储左、右、中的最长0/1长度
    void init() {
        lx[0] = lx[1] = 0;
        rx[0] = rx[1] = 0;
        mx[0] = mx[1] = 0;
    }
} tree[N << 2];

node push_up(node x, node y) {
    node z;
    z.init();
    z.len = x.len + y.len;
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
        if (a[l]) tree[id].lx[1] = tree[id].rx[1] = tree[id].mx[1] = 1;
        else tree[id].lx[0] = tree[id].rx[0] = tree[id].mx[0] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    tree[id] = push_up(tree[id << 1], tree[id << 1 | 1]);
}

void swapper(int id) {
    swap(tree[id].lx[0], tree[id].lx[1]);
    swap(tree[id].rx[0], tree[id].rx[1]);
    swap(tree[id].mx[0], tree[id].mx[1]);
}

void push_down(int id) {
    if (lazy[id]) {
        lazy[id << 1] ^= 1;
        lazy[id << 1 | 1] ^= 1;
        swapper(id << 1), swapper(id << 1 | 1);
        lazy[id] = 0;
    }
}

void modify(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        lazy[id] ^= 1;
        swapper(id);
        return;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    if (L <= mid) modify(id << 1, l, mid, L, R);
    if (R > mid) modify(id << 1 | 1, mid + 1, r, L, R);
    tree[id] = push_up(tree[id << 1], tree[id << 1 | 1]);
}

node query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[id];
    push_down(id);
    int mid = (l + r) >> 1;
    if (R <= mid) return query(id << 1, l, mid, L, R);
    if (L > mid) return query(id << 1 | 1, mid + 1, r, L, R);
    return push_up(query(id << 1, l, mid, L, R), query(id << 1 | 1, mid + 1, r, L, R));
}

void debug() {
    for (int i = 1; i <= 7; ++i) {
        cout << i << endl;
        cout << "len:" << tree[i].len << endl;
        cout << 1 << ':' << tree[i].lx[1] << ' ' << tree[i].rx[1] << ' ' << tree[i].mx[1] << endl;
        cout << 0 << ':' << tree[i].lx[0] << ' ' << tree[i].rx[0] << ' ' << tree[i].mx[0] << endl;
        cout << "----------------" << endl;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    build(1, 1, n);
    scanf("%d", &m);
    int x, l, r;
    while (m--) {
        scanf("%d%d%d", &x, &l, &r);
        if (!x) printf("%d\n", query(1, 1, n, l, r).mx[1]);
        else {
            modify(1, 1, n, l, r);
            // debug();
        }
    }
    return 0;
}