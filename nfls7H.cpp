#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m, tree[N << 2];
void build(int id, int l, int r) {
    tree[id] = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}
int query(int id, int l, int r, int k) {
    --tree[id];
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (tree[id << 1] >= k) return query(id << 1, l, mid, k);
    else return query(id << 1 | 1, mid + 1, r, k - tree[id << 1]);
}
int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        k = (k + m - 1) % (n - i + 1);
        if (!k) k = n - i + 1;
        printf("%d ", query(1, 1, n, k));
    }
    return 0;
}