#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, dep[N], jump[30][N], logn;
bool mark[N];
vector<int> g[N], seta, setb;
void dfs(int x, int fa) {
    jump[0][x] = fa;
    dep[x] = dep[fa] + 1;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y ^ fa) dfs(y, x);
    }
}
void initJump() {
    for (int i = 1; i <= logn; ++i) 
        for (int j = 1; j <= n; ++j) 
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
}
int jmp(int x, int y) {
    for (int i = logn; i >= 0; --i) {
        if (y - (1 << i) >= 0 && x) {
            x = jump[i][x];
            y -= 1 << i;
        }
    }
    return x;
}
bool check(int mid) {
    vector<int> v;
    for (int i = 0; i < seta.size(); ++i) 
        if (dep[seta[i]] >= mid) {
            int res = jmp(seta[i], dep[seta[i]] - mid);
            mark[res] = true;
            v.push_back(res);
        }
    bool ans = false;
    for (int i = 0; i < setb.size(); ++i) 
        if (dep[setb[i]] >= mid && mark[jmp(setb[i], dep[setb[i]] - mid)]) {
            ans = true;
            break;
    }
    for (int i = 0; i < v.size(); ++i) mark[v[i]] = false;
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    logn = log2(n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    initJump();
    int k, t;
    while (m--) {
        seta.clear(); setb.clear();
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &t); seta.push_back(t);
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &t); setb.push_back(t);
        }
        int l = 0, r = n - 1, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}