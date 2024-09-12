#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N], b[N];
int n, m, q;
struct node {
    ll maxZ, maxF, minZ, minF, zero;
} tree1[4 * N];
struct node2 {
    ll maxZ, minZ;
} tree2[4 * N];
void pushup1(int id) {
    tree1[id].maxZ = max(tree1[id << 1].maxZ, tree1[id << 1 | 1].maxZ);
    tree1[id].minZ = min(tree1[id << 1].minZ, tree1[id << 1 | 1].minZ);
    tree1[id].maxF = max(tree1[id << 1].maxF, tree1[id << 1 | 1].maxF);
    tree1[id].minF = min(tree1[id << 1].minF, tree1[id << 1 | 1].minF);
    tree1[id].zero = max(tree1[id << 1].zero, tree1[id << 1 | 1].zero);
}
void build1(int id, int l, int r) {
    if (l == r) {
        if (a[l] > 0) {
            tree1[id].maxZ = a[l];
            tree1[id].minZ = a[l];
            tree1[id].maxF = -inf;
            tree1[id].minF = inf;
            tree1[id].zero = 0;
        } else if (a[l] < 0) {
            tree1[id].maxZ = -inf;
            tree1[id].minZ = inf;
            tree1[id].maxF = a[l];
            tree1[id].minF = a[l];
            tree1[id].zero = 0;
        } else {
            tree1[id].maxZ = -inf;
            tree1[id].minZ = inf;
            tree1[id].maxF = -inf;
            tree1[id].minF = inf;
            tree1[id].zero = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build1(id << 1, l, mid);
    build1(id << 1 | 1, mid + 1, r);
    pushup1(id);
}
ll queryMaxF(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree1[id].maxF;
	int mid = (l + r) >> 1;
    ll ans = -inf;
	if (L <= mid) 
        ans = max(ans, queryMaxF(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = max(ans, queryMaxF(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
ll queryMaxZ(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree1[id].maxZ;
	int mid = (l + r) >> 1;
    ll ans = -inf;
	if (L <= mid) 
        ans = max(ans, queryMaxZ(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = max(ans, queryMaxZ(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
ll queryMinZ(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree1[id].minZ;
	int mid = (l + r) >> 1;
    ll ans = inf;
	if (L <= mid) 
        ans = min(ans, queryMinZ(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = min(ans, queryMinZ(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
ll queryMinF(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree1[id].minF;
	int mid = (l + r) >> 1;
    ll ans = inf;
	if (L <= mid) 
        ans = min(ans, queryMinF(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = min(ans, queryMinF(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
ll queryZero(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree1[id].zero;
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid) 
        ans = max(ans, queryZero(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = max(ans, queryZero(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
void pushup2(int id) {
    tree2[id].maxZ = max(tree2[id << 1].maxZ, tree2[id << 1 | 1].maxZ);
    tree2[id].minZ = min(tree2[id << 1].minZ, tree2[id << 1 | 1].minZ);
}
void build2(int id, int l, int r) {
    if (l == r) {
        tree2[id].maxZ = b[l];
        tree2[id].minZ = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build2(id << 1, l, mid);
    build2(id << 1 | 1, mid + 1, r);
    pushup2(id);
}
ll query2MaxZ(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree2[id].maxZ;
    int mid = (l + r) >> 1;
    ll ans = -inf;
    if (L <= mid) 
        ans = max(ans, query2MaxZ(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = max(ans, query2MaxZ(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
ll query2MinZ(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return tree2[id].minZ;
    int mid = (l + r) >> 1;
    ll ans = inf;
    if (L <= mid) 
        ans = min(ans, query2MinZ(id << 1, l, mid, L, R));
    if (R > mid) 
        ans = min(ans, query2MinZ(id << 1 | 1, mid + 1, r, L, R));
    return ans;
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) 
        scanf("%lld", a + i);
    for (int i = 1; i <= m; ++i) 
        scanf("%lld", b + i);
    build1(1, 1, n);
    build2(1, 1, m);
    int l1, r1, l2, r2;
    while (q--) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        ll xt[10];
        xt[1] = queryMaxZ(1, 1, n, l1, r1);
        xt[2] = queryMaxF(1, 1, n, l1, r1);
        xt[3] = queryMinZ(1, 1, n, l1, r1);
        xt[4] = queryMinF(1, 1, n, l1, r1);
        xt[5] = query2MaxZ(1, 1, m, l2, r2);
        xt[6] = query2MinZ(1, 1, m, l2, r2);
        ll ans = -inf;
        for (int i = 1; i <= 4; ++i) {
            for (int j = 5; j <= 6; ++j) {
                if (xt[i] == inf || xt[i] == -inf || xt[j] == inf || xt[j] == -inf) 
                    continue;
                ans = max(ans, xt[i] * xt[j]);
            }
        }
        if (queryZero(1, 1, n, l1, r1)) {
            for (int i = 5; i <= 6; ++i) {
                ans = max(ans, xt[i] * 0);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
