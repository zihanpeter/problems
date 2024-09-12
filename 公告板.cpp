#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int h, w, n, tree[N << 2];
void pushUp(int id) {
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = w;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushUp(id);
}
int query(int id, int l, int r, int x) {
    if (l == r) 
        return l;
    int mid = (l + r) >> 1;
    if (tree[id << 1] >= x) 
        return query(id << 1, l, mid, x);
    else
        return query(id << 1 | 1, mid + 1, r, x);
}
void update(int id, int l, int r, int x, int y) {
    if (l == r) {
        tree[id] += y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) 
        update(id << 1, l, mid, x, y);
    else 
        update(id << 1 | 1, mid + 1, r, x, y);
    pushUp(id);
}
int main() {
    scanf("%d%d%d", &h, &w, &n);
    build(1, 1, min(n, h));
    int t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        if (tree[1] < t) {
            printf("-1\n");
        } else {
            int pos = query(1, 1, min(n, h), t);
            printf("%d\n", pos);
            update(1, 1, min(n, h), pos, -t);
        }
    }
    return 0;
}