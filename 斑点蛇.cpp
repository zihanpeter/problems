#include <iostream>
using namespace std;
const int N = 5e4 + 5;
int n, a[N], tree[N << 4];
void pushUp(int id) {
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
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
int query(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) 
        return tree[id];
    int mid = (l + r) >> 1, ans = 0;
    if (x <= mid) 
        ans += query(id << 1, l, mid, x, y);
    if (y > mid) 
        ans += query(id << 1 | 1, mid + 1, r, x, y);
    return ans;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    build(1, 1, n);
    string s;
    int x, y;
    while (true) {
        cin >> s;
        if (s == "Add") {
            cin >> x >> y;
            update(1, 1, n, x, y);
        } else if (s == "Sub") {
            cin >> x >> y;
            update(1, 1, n, x, -y);
        } else if (s == "Query") {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        } else 
            break;
    }
    return 0;
}