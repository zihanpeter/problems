#include <iostream>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
struct node {
    int mx, sum; // mx收益，sum总和
} tree[N << 2];
int n, q, x[N], y[N], a[N], b[N];

void push_up(int id) {
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
    tree[id].mx = max(tree[id << 1].mx, tree[id << 1 | 1].mx);
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].sum = a[l];
        tree[id].mx = a[l] + a[l - 1] - b[l + 1];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    push_up(id);
}

int querySum(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[id].sum;
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid) ans += querySum(id << 1, l, mid, L, R);
    if (R > mid) ans += querySum(id << 1 | 1, mid + 1, r, L, R);
    return ans;
}

int queryMax(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[id].mx;
    int mid = (l + r) >> 1, ans = -INF;
    if (L <= mid) ans = max(ans, queryMax(id << 1, l, mid, L, R));
    if (R > mid) ans = max(ans, queryMax(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}

void update(int id, int l, int r, int x) {
    if (l == r) {
        tree[id].mx = a[l - 1] + a[l] - b[l + 1];
        tree[id].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(id << 1, l, mid, x);
    else update(id << 1 | 1, mid + 1, r, x);
    push_up(id);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
    for (int i = 1; i < n; ++i) a[i] = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    for (int i = 2; i <= n; ++i) b[i] = abs(x[i] - x[i - 2]) + abs(y[i] - y[i - 2]);
    build(1, 1, n - 1);
    char mode;
    int i, xi, yi;
    while (q--) {
        cin >> mode;
        if (mode == 'U') {
            cin >> i >> xi >> yi;
            x[i] = xi, y[i] = yi;
            a[i] = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
            a[i - 1] = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
            b[i] = abs(x[i] - x[i - 2]) + abs(y[i] - y[i - 2]);
            b[i + 2] = abs(x[i + 2] - x[i]) + abs(y[i + 2] - y[i]);
            b[i + 1] = abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]);
            update(1, 1, n - 1, i - 1);
            update(1, 1, n - 1, i);
            update(1, 1, n - 1, i + 1);
            update(1, 1, n - 1, i + 2);
        } else {
            cin >> xi >> yi;
            int res = queryMax(1, 1, n - 1, xi + 1, yi - 1);
            if (res < 0) cout << querySum(1, 1, n - 1, xi, yi - 1) << '\n';
            else cout << querySum(1, 1, n - 1, xi, yi - 1) - res << '\n';
        }
    }
    return 0;
}













