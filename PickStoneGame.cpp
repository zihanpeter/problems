#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 3e3 + 5;
int s[N], info[N], n;
vector<int> g[N];
int dfs(int x, int fa) {
    if (info[x] != -1) 
        return info[x];
    info[x] = 0;
    if (s[x] > s[fa] && fa != 0 && info[fa] != 1) 
        info[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        if (dfs(y, x) == 0) 
            info[x] = 1; 
    }
    return info[x];
}
int main() {
    memset(info, -1, sizeof(info));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", s + i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    bool flag = true;
    for (int i = 1; i <= n; ++i) 
        if (info[i] == 1) { 
            printf("%d ", i);
            flag = false;
        }
    if (flag) 
        printf("-1");
    return 0;
}