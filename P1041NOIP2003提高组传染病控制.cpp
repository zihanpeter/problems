#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
vector<int> g[N], level[N];
int n, p, deep[N], size[N], maxLevel, realAns = 0x3f3f3f3f, father[N];
bool ill[N];
void dfsds(int x, int fa) { 
    deep[x] = deep[fa] + 1;
    level[deep[x]].push_back(x);
    maxLevel = max(maxLevel, deep[x]);
    size[x] = 1;
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfsds(y, x);
        size[x] += size[y];
    }
}
void dfsdel(int x, int fa) { 
    ill[x] = true;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfsdel(y, x);
    }
}
void dfsadd(int x, int fa) { 
    ill[x] = false;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfsadd(y, x);
    }
}
void dfs(int l, int ans) { 
    realAns = min(realAns, ans);
    for (int i = 0; i < level[l].size(); ++i) {
        int x = level[l][i];
        if (ill[x]) 
            continue;
        dfsdel(x, father[x]);
        dfs(l + 1, ans - size[x]);
        dfsadd(x, father[x]);
    }
}
int main() {
    scanf("%d%d", &n, &p);
    int u, v;
    for (int i = 1; i <= p; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsds(1, 0);
    dfs(2, n);
    printf("%d", realAns);
    return 0;
}