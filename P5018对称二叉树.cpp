#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, w[N], ans;
struct node {
	int l, r;
} g[N];
bool judge(int x, int y) {
	if (x == -1 && y == -1) 
		return true;
	if (x == -1 || y == -1)
		return false;
	if (w[x] != w[y])
		return false;
	return judge(g[x].l, g[y].r) && judge(g[x].r, g[y].l);
}
int dfs(int x) {
	if (x == -1)
		return 0;
	return dfs(g[x].l) + dfs(g[x].r) + 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", w + i);
	for (int i = 1; i <= n; ++i) 
		scanf("%d%d", &g[i].l, &g[i].r);
	for (int i = 1; i <= n; ++i) 
        if (judge(g[i].l, g[i].r))
            ans = max(ans, dfs(i));
	printf("%d", ans);
	return 0;
}