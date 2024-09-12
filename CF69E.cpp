#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, k, a[N], m, b[N], to[N];
struct node {
    int val, num; 
} tree[N << 2];

void push_up(int id) {
    tree[id].val = max(tree[id << 1].val, tree[id << 1 | 1].val);
}

void update(int id, int l, int r, int x, int opt) {
    if (l == r) {
        tree[id].num += opt;
        if (tree[id].num == 1) tree[id].val = x;
        else tree[id].val = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(id << 1, l, mid, x, opt);
    else update(id << 1 | 1, mid + 1, r, x, opt);
    push_up(id);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i) {
        int t = lower_bound(b + 1, b + m + 1, a[i]) - b;
        to[t] = a[i];
        a[i] = t;
    } 
    for (int i = 1; i < k; ++i) update(1, 1, m, a[i], 1);
    for (int i = k; i <= n; ++i) {
        update(1, 1, m, a[i], 1);
        if (tree[1].val == 0) printf("Nothing\n");
        else printf("%d\n", to[tree[1].val]);
        update(1, 1, m, a[i - k + 1], -1);
    }
    return 0;
}