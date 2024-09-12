#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, deep[N], father[N], logn, jump[N][30], info[N];
bool H[N][30], G[N][30];
vector<int> g[N];
string temp;
void dfs(int x, int fa) {
    deep[x] = deep[fa] + 1;
    father[x] = fa;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        dfs(y, x);
    }
}
void initJump() {
    for (int i = 1; i <= n; ++i) 
        jump[i][0] = father[i];
    for (int j = 1; j <= logn; ++j) 
        for (int i = 1; i <= n; ++i) 
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
}
bool lca(int x, int y, int mode) {
    if (info[x] == mode || info[y] == mode)
        return true;
    if (deep[x] < deep[y]) 
        swap(x, y);
    int dis = deep[x] - deep[y];
    int k = 0;
    while (dis) {
        if (dis % 2 == 1) {
            if (mode == 0 && H[x][k]) return true;
            if (mode == 1 && G[x][k]) return true;
			x = jump[x][k];
        }
        dis /= 2;
        ++k;
    }
    if (x == y) 
        return false;
    for (int i = logn; i >= 0; --i) {
        if (jump[x][i] == jump[y][i])  
            continue;
        if (mode == 0 && H[x][i]) return true;
        if (mode == 1 && G[x][i]) return true;
        if (mode == 0 && H[y][i]) return true;
        if (mode == 1 && G[y][i]) return true; 
		y = jump[y][i];
		x = jump[x][i];
    }
    if (info[jump[x][0]] == mode) return true;
    return false;
}
void initHG() {
    for (int i = 1; i <= n; ++i) {
    	if (info[i] == 0 || info[father[i]] == 0) 
    		H[i][0] = true;
		if (info[i] == 1 || info[father[i]] == 1)
			G[i][0] = true;
    }
    for (int j = 1; j <= logn; ++j) {
        for (int i = 1; i <= n; ++i) {
            H[i][j] = H[i][j - 1] || H[jump[i][j - 1]][j - 1];
            G[i][j] = G[i][j - 1] || G[jump[i][j - 1]][j - 1];
        }
    }
}
string ansStr;
int main() {
    cin >> n >> m;
    cin >> temp;
    for (int i = 1; i <= n; ++i) {
        if (temp[i - 1] == 'H') 
            info[i] = 0;
        if (temp[i - 1] == 'G')
            info[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    logn = log2(n);
    initJump();
    initHG();
    for (int i = 1; i <= m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        bool ans;
        if (c == 'H') 
            ans = lca(a, b, 0);
        else 
            ans = lca(a, b, 1);
        if (ans) 
            ansStr += '1';
        else 
            ansStr += '0';
    }
    cout << ansStr << endl;
    return 0;
}
