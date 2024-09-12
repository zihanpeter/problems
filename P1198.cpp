#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, d, tree[N << 2], lazy[N << 2];
void pushUp(int id) {
    tree[id] = (tree[id << 1] + tree[id << 1 | 1]) % d;
}
void pushDown(int id, int l, int r) {
    if (lazy[id]) {
        int mid = (l + r) >> 1;
        lazy[id << 1] = (lazy[id << 1] + lazy[id]) % d;
        lazy[id << 1 | 1] = (lazy[id << 1 | 1] + lazy[id]) % d;
        tree[id << 1] = (tree[id << 1] + lazy[id] * (mid - l + 1)) % d;
        tree[id << 1 | 1] = (tree[id << 1 | 1] + lazy[id] * (r - mid)) % d;
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, int L, int R, int v) {
    if (L <= l && r <= R) {
        lazy[id] = (lazy[id] + v) % d;
        tree[id] = (tree[id] + (r - l + 1) * v) % d;
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
int query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree[id];
    pushDown(id, l, r);
    int mid = (l + r) >> 1;
    int ans = 0; 
    if (L <= mid) 
        ans = (ans + query(id << 1, l, mid, L, R)) % d;
    if (R > mid) 
        ans = (ans + query(id << 1 | 1, mid + 1, r, L, R)) % d;
    return ans;
}
int main() {
    int m;
    cin >> m >> d;
    char c;
    int k;
    while (m--) {
        cin >> c >> k;
        if (c == 'Q') {
            cout << query(1, 1, n, n - )
        } else {

        }
    }
    return 0;
}