#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, timeStaff, dfn[N], low[N], ans[N];
vector<int> g[N];
void dfs(int x, int fa) {
    dfn[x] = low[x] = ++timeStaff;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == fa) 
            continue;
        else if (dfn[y] == 0) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                ++ans[x];
            }
        } else 
            low[x] = min(low[x], dfn[y]);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int res = 0, pos;
    for (int i = 1; i <= n; ++i) {
    	if (ans[i] > res) {
    		res = ans[i];
    		pos = i;
		}
	} 
	printf("%d %d", pos, res);
	cout << endl;
	cout << ans[5] << ' ';
    return 0;
}
