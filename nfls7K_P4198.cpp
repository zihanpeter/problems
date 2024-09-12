#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m;
struct node {
    double x; // x最大值
    int l; // l最大长度
} tree[N << 2];

void push_up(int id) {
    tree[id].x = max(tree[id << 1].x, tree[id << 1 | 1].x);
}

int merge(double lmax, int id, int l, int r) {
    if (l == r) return tree[id].x > lmax;
    int mid = (l + r) >> 1;
    if (tree[id << 1].x <= lmax) return merge(lmax, id << 1 | 1, mid + 1, r);
    else return merge(lmax, id << 1, l, mid) + tree[id].l - tree[id << 1].l;
}

void update(int id, int l, int r, int x, double k) {
    if (l == r) {
        tree[id].x = k;
        tree[id].l = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(id << 1, l, mid, x, k);
    else update(id << 1 | 1, mid + 1, r, x, k);
    push_up(id);
    tree[id].l = tree[id << 1].l + merge(tree[id << 1].x, id << 1 | 1, mid + 1, r);
}

int main() {
    freopen("nfls7K.in", "r", stdin);
    scanf("%d%d", &n, &m);
    int x, y;
    while (m--) {
        scanf("%d%d", &x, &y);
        double k = 1.0 * y / x;
        update(1, 1, n, x, k);
        printf("%d\n", tree[1].l);
    }
    return 0;
}