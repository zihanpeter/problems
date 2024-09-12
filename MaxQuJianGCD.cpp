#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;
int n, q, a[N], tree[N << 2], ans;
void pushUp(int id) {
    tree[id] = __gcd(tree[id << 1], tree[id << 1 | 1]);
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
void update(int id, int l, int r, int x, int y) {
    if (l == r) {
        tree[id] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) 
        update(id << 1, l, mid, x, y);
    else 
        update(id << 1 | 1, mid + 1, r, x, y);
    pushUp(id);
}
int query(int id, int l, int r, int x, int y, int v) {
    if (l == r) {
        if (tree[id] % v == 0) 
             return 0;
        return 1;
    }
    int mid = (l + r) >> 1, ans1 = 0, ans2 = 0;
    if (x <= mid) {
        if (tree[id << 1] % v != 0) 
            ans1 = query(id << 1, l, mid, x, y, v); 
        if (ans1 >= 2) 
            return 2;
    }
    if (y > mid) {
        if (tree[id << 1 | 1] % v != 0) 
            ans2 = query(id << 1 | 1, mid + 1, r, x, y, v);
        if (ans1 + ans2 >= 2)
            return 2;
    }
    return ans1 + ans2;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i); 
    build(1, 1, n);
    scanf("%d", &q);
    int mode, l, r, x, y;
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &mode);
        if (mode == 1) {
            scanf("%d%d%d", &l, &r, &x);
            if (query(1, 1, n, l, r, x) <= 1) 
                printf("yes\n");
            else 
                printf("no\n");
        } else {
            scanf("%d%d", &l, &y);
            update(1, 1, n, l, y);
        }
    }
    return 0;
}
