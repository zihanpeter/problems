#include <iostream>
using namespace std;

const int N = 20 + 5;

int n, m, ans;
bool vis[N][N];
int cx[] = {1, -1, 0, 0};
int cy[] = {0, 0, 1, -1};
char s[N][N];

void dfs(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int tx = cx[i] + x, ty = cy[i] + y;
		if (tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty] == '#' || vis[tx][ty]) 
			continue;
		vis[tx][ty] = true;
		++ans;
		dfs(tx, ty);
	}
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) 
		if (s[i][j] == '@') {
			vis[i][j] = true;
			++ans;
			dfs(i, j);
		}
	printf("%d", ans);
	return 0;
}
