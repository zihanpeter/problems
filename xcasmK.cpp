#include <iostream>
#include <queue>
using namespace std;
const int N = 5e4 + 5;
int n, cnt, dep[N], ans;
struct node {
    int v, l, r, num;
} a[N];
bool operator > (const node &x, const node &y) {
    return x.v > y.v;
}
priority_queue<node, vector<node>, greater<node> > pq;

void dfs(int x, int f) {
    dep[x] = dep[f] + 1;
    if (x <= n) ans += dep[x] * a[x].v;
    if (a[x].l) dfs(a[x].l, x);
    if (a[x].r) dfs(a[x].r, x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].v);
        a[i].num = ++cnt;
        pq.push(a[i]);
    }
    while (pq.size() > 1) {
        node x = pq.top(); pq.pop();
        node y = pq.top(); pq.pop();
        a[++cnt].v = x.v + y.v;
        a[cnt].l = x.num; a[cnt].r = y.num;
        a[cnt].num = cnt;
        pq.push(a[cnt]);
    }
    dep[0] = -1;
    dfs(pq.top().num, 0);
    printf("%d", ans);
    return 0;
}