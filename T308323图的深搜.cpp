#include <cstdio>
#include <vector>
using namespace std;
const int N = 5e3 + 5;
bool g[N][N];
char sides[N][N];
int n, m, timeBuff, grayTime[N], blackTime[N], col[N];
struct node {
	int u, v;
} sideSave[N];
void dfs(int x) {
	++timeBuff;
	grayTime[x] = timeBuff;
	col[x] = 1;
	for (int i = 1; i <= n; ++i) 
		if (g[x][i]) {
			int y = i;
			if (col[y] == 0) {
				if (sides[x][y] == 0) 
					sides[x][y] = 'T';
				dfs(y);
			} else if (col[y] == 1) {
				if (sides[x][y] == 0) 
					sides[x][y] = 'B';
			} else if (col[y] == -1) {
				if (grayTime[x] < grayTime[y] && sides[x][y] == 0) 
					sides[x][y] = 'F';
				else if (grayTime[x] > grayTime[y] && sides[x][y] == 0) 
					sides[x][y] = 'C';
			}
		}
	++timeBuff;
	blackTime[x] = timeBuff;
	col[x] = -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = true;
		sideSave[i] = node{u, v};
	}
	for (int i = 1; i <= n; ++i) 
		if (blackTime[i] == 0) 
			dfs(i);
	for (int i = 1; i <= n; ++i) 
		printf("%d %d\n", grayTime[i], blackTime[i]);
	for (int i = 1; i <= m; ++i) 
		printf("%c\n", sides[sideSave[i].u][sideSave[i].v]);
	return 0;
} 
