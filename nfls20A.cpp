#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, INF = 0x3f3f3f3f;
int n, m, cnt = -1, nxt[N], head[N], to[N], a[N], Li[N], Ri[N], tot, tree[N << 1], num[N];

void add(int u, int v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }

void dfs(int x, int fa) {
    Li[x] = ++tot;
    num[tot] = x;
    for (int i = head[x]; ~i; i = nxt[i]) {
        int y = to[i];
        if (y ^ fa) dfs(y, x);
    }
    Ri[x] = tot;
}

void push_up(int id) {
    int ll = tree[id << 1], rr = tree[id << 1 | 1];
    if (a[ll] > a[rr])
        tree[id] = ll;
    else if (a[ll] < a[rr]) 
        tree[id] = rr;
    else if (a[ll] == a[rr]) 
        tree[id] = ll < rr ? ll : rr;
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    push_up(id);
    
}

int query(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[id];
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid) {
        int res = query(id << 1, l, mid, L, R);
        if (a[res] > a[ans]) ans = res;
        else if (a[res] == a[ans] && (res < ans || !ans)) ans = res;
    }
    if (R > mid) {
        int res = query(id << 1 | 1, mid + 1, r, L, R);
        if (a[res] > a[ans]) ans = res;
        else if (a[res] == a[ans] && (res < ans || !ans)) ans = res;
    }
    return ans;
}

void update(int id, int l, int r, int x) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid) update(id << 1, l, mid, x);
    else update(id << 1 | 1, mid + 1, r, x);
    push_up(id);
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    int opt, u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    build(1, 1, n);
    while (m--) {
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d", &u);
            int res = query(1, 1, n, Li[u], Ri[u]);
            printf("%d\n", res);
            a[res] = 0;
            update(1, 1, n, Li[res]);
        } else {
            scanf("%d%d", &u, &v);
            a[u] += v;
            update(1, 1, n, Li[u]);
        }
    }
    return 0;
}