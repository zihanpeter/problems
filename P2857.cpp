#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int k, n, m;
vector<int> g[N];
bool pos[N], vis[N];
int points[N], ans;
void dfs(int x, int cnt) {
	vis[x] = true;
    points[x] += cnt;
	for (int i = 0; i < g[x].size(); ++i) {
		if (!vis[g[x][i]]) {
            if (pos[g[x][i]])
			dfs(g[x][i]);
		}
	}
}
int main() {
	cin >> k >> n >> m;
	int x, y;
	for (int i = 1; i <= k; ++i) {
		cin >> x;
		pos[x] = true;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		memset()
	}
	cout << ans;
	return 0;
}