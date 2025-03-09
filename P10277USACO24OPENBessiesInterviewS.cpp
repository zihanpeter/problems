#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int N = 3e5 + 5;
int n, m, k, ft[N], fb[N], b[N << 1];
struct node {
    int id, t;
} nds[N];
bool operator > (const node &x, const node &y) {
    return x.t > y.t;
}
priority_queue<node, vector<node>, greater<node> > pq;
vector<int> g[N];
bool tong[N], vis[N];

int getnum(int x) { return upper_bound(b + 1, b + m + 1, x) - b; }

void con() {
    for (int i = 1; i <= n; ++i) b[i] = ft[i];
    for (int i = 1; i <= n; ++i) fb[i] = ft[i] - nds[i].t;
    for (int i = n + 1; i <= n << 1; ++i) b[i] = fb[i - n];
    sort(b + 1, b + (n << 1) + 1);
    m = unique(b + 1, b + (n << 1) + 1) - b;
    for (int i = 1; i <= n; ++i) {
        ft[i] = getnum(ft[i]);
        fb[i] = getnum(fb[i]);
    }
}

void dfs(int x) {
    if (x < 2) return;
    for (int idx : g[x]) {
        if (fb[idx] == 2)
            tong[idx] = true;
        else if (!vis[idx]) {
            vis[idx] = true;
            dfs(fb[idx]);
        }
    }
}

main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &nds[i].t);
        nds[i].id = i;
    }
    for (int i = 1; i <= k; ++i) {
        pq.push(nds[i]);
        ft[i] = nds[i].t;
    }
    int cur = k, ans = -1;
    while (!pq.empty()) {
        int x = pq.top().id, t = pq.top().t, cnt = 1;
        pq.pop();
        while (!pq.empty() && pq.top().t == t) {
            ++cnt;
            pq.pop();
        }
        for (int i = cur + 1; i <= cur + cnt; ++i) {
            ft[i] = nds[i].t + t;
            if (i == n + 1) {
                ans = t;
                break;
            }
            pq.push(node{nds[i].id, ft[i]});
        }
        cur += cnt;
        if (~ans) break;
    }
    printf("%lld\n", ans);
    con();
    for (int i = 1; i <= n; ++i) g[ft[i]].push_back(i);
    vis[n + 1] = true;
    dfs(getnum(ans));
    for (int i = 1; i <= k; ++i) {
        if (tong[i]) putchar('1');
        else putchar('0');
    }
    return 0;
}