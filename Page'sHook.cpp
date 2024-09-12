#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, q, tree[N << 2], lazy[N << 2];
void pushUp(int id) {
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
void pushDown(int id, int l, int r) {
    if (lazy[id]) {
        int mid = (l + r) >> 1;
        // cout << id << endl;
        lazy[id << 1] = lazy[id];
        lazy[id << 1 | 1] = lazy[id];
        tree[id << 1] = (mid - l + 1) * lazy[id];
        tree[id << 1 | 1] = (r - mid) * lazy[id];
        lazy[id] = 0;
    }
}
void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushUp(id);
}
void update(int id, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        lazy[id] = v;
        tree[id] = (r - l + 1) * v;
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
int main() {
    scanf("%d%d", &n, &q);
    build(1, 1, n);
    int x, y, z;
    while (q--) {
        scanf("%d%d%d", &x, &y, &z);
        update(1, 1, n, x, y, z);
    }
    printf("The total value of the hook is %d.", tree[1]);
    return 0;
}