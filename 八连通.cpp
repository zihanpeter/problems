#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[110][110];
int zx[8] = {1, 0,-1, 0,-1, 1, 1,-1};
int zy[8] = {0, 1, 0,-1, 1,-1, 1,-1};
void dfs(int x, int y){
	a[x][y] = '.';
	for (int i = 0;i < 8;i++){
		int tx = x + zx[i];
		int ty = y + zy[i];
		if (tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] == '.'){
			continue;
		}
		dfs(tx, ty);
	}
} 
int main(){
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			if (a[i][j] == 'W'){
				dfs(i, j);
				ans++;
			}
		}
	} 
	cout<<ans;
	return 0;
}
