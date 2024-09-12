#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
vector<int> g[N];
int n, m, eularSort[N], pos1[N], last, minValue[4 * N];
void dfs(int x, int fa) {
	eularSort[++last] = x;
	pos1[x] = last;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		dfs(y, x);
		eularSort[++last] = x;
	}
	return;
}
void pushUp(int id) {
	minValue[id] = min(minValue[id << 1], minValue[id << 1 | 1]);
	return;
}
void build(int id, int l, int r) {
	if (l == r) {
		minValue[id] = eularSort[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushUp(id);
	return;
}
int query(int id, int l, int r, int x, int y) {
	if (x <= l && r <= y)
		return minValue[id];
	int mid = (l + r) >> 1;
	int ans = inf;
	if (x <= mid)
		ans = min(ans, query(id << 1, l, mid, x, y));
	if (y > mid)
		ans = min(ans, query(id << 1 | 1, mid + 1, r, x, y));
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	build(1, 1, last);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", query(1, 1, last, min(pos1[x], pos1[y]), max(pos1[x], pos1[y])));
	}
	return 0;
}
