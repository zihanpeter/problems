#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
vector<int> g[N];
int n, timeStaff, dfn[N], low[N];
bool cuts[N];
void dfs(int x, int fa) {
	dfn[x] = low[x] = ++timeStaff;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == fa) 
			continue;
		if (dfn[y] == 0) {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) 
				cuts[x] = true;	
		} else 
			low[x] = min(low[x], dfn[y]);
	}
	return;
}
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) 
			break;
		while (true) {
			int u, temp = 0, cnt = 0;
			char c;
			bool flag = false;
			for (int i = 1; i <= n; ++i) 
				g[i].clear();
			while (true) {
				c = getchar();
				if (c == ' ') {
					++cnt;
					if (cnt == 1) {
						u = temp;
						temp = 0;
					} else {
						g[u].push_back(temp);
						temp = 0;
					}
				} else if (c == '\n') {
					if (cnt == 0 && temp == 0) 
						flag = true;
					else 
						g[u].push_back(temp);
					break;
				} else {
					temp *= 10;
					temp += c - '0';
				}
			}
			if (flag) 
				break;
		}
		timeStaff = 0;
		memset(low, 0, sizeof(low));
		memset(dfn, 0, sizeof(dfn));
		memset(cuts, 0, sizeof(cuts));
		dfs(1, 0);
		int ans = 0;
		for (int i = 1; i <= n; ++i) 
			if (cuts[i])
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}
