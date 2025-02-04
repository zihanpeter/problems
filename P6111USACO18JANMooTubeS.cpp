#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, q, ans[N], siz[N], f[N];
struct node {
    int u, v, w;
} nds[N], ques[N];
bool cmp(node x, node y) { return x.w > y.w; }

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx ^ fy) {
        f[fx] = fy;
        siz[fy] += siz[fx];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) f[i] = i, siz[i] = 1;
    for (int i = 1; i < n; ++i) cin >> nds[i].u >> nds[i].v >> nds[i].w;
    for (int i = 1; i <= q; ++i) {
        cin >> ques[i].w >> ques[i].v;
        ques[i].u = i;
    }
    sort(nds + 1, nds + n, cmp);
    sort(ques + 1, ques + q + 1, cmp);
    int id = 1;
    for (int i = 1; i <= q; ++i) {
        while (id < n && ques[i].w <= nds[id].w) {
            merge(nds[id].u, nds[id].v);
            ++id;
        }
        ans[ques[i].u] = siz[find(ques[i].v)] - 1;
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}