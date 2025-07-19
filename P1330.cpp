#include <iostream>
#include <vector>
#include <string>
using namespace std; 
int n, m;
vector<int> g[10005];
int cntRed, cntBlue, sum;
int vis[10005];
void dfs(int x, int info) {
	if(vis[x] == -info) {
		cout << "Impossible";
		exit(0);
	}
	if (vis[x] == info) return;
	vis[x] = info;
	if (info == 1) ++cntRed;
	else ++cntBlue;
	for (int i = 0; i < g[x].size(); ++i) dfs(g[x][i], -info);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) 
		if (vis[i] == 0) {
			cntRed = cntBlue = 0; 
			dfs(i, 1);
			sum += min(cntRed, cntBlue);
		}
	cout << sum;
	return 0;
} 
