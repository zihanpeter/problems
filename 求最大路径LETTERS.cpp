/*#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char a[21][21];
int vis[21][21];
int tong[26];
int cx[4] = {0, 0, -1, 1};
int cy[4] = {-1, 1, 0, 0};
int ans = -0x3f3f3f3f;
void dfs(int x, int y, int step){
	for(int i=0;i<4;i++){
		int tx = cx[i] + x;
		int ty = cy[i] + y;
		int temo = a[tx][ty]-'A';
		if(tx<1 || tx>n || ty<1 || ty>m || tong[temo]!=0){
			continue;
		}
		ans = max(step, ans);
		tong[temo] = 1;
		//vis[tx][ty] = 1;
		//cout<<tx<<' '<<ty<<endl;
		dfs(tx, ty, step+1);
		tong[temo] = 0;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int temo = a[1][1]-'A';
	tong[temo] = 1;
	dfs(1, 1, 1);
	cout<<ans+1<<endl;
	return 0;
}
*/

#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char a[21][21];
int vis[21][21];
int tong[26];
int cx[4] = {0, 0, -1, 1};
int cy[4] = {-1, 1, 0, 0};
int ans;
void dfs(int x, int y, int step) {
	for(int i=0; i<4; i++) {
		int tx = cx[i] + x;
		int ty = cy[i] + y;
		int temo = a[tx][ty]-'A';
		if(tx<1 || tx>n || ty<1 || ty>m || tong[temo]!=0 || vis[tx][ty]==1) {
			continue;
		}
		if(step > ans){
			ans = step;
		}
		tong[temo] = 1;
		vis[tx][ty] = 1;
		dfs(tx, ty, step+1);
		tong[temo] = 0;
		vis[tx][ty] = 0;
	}
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	tong[a[1][1]-'A'] = 1;
	vis[1][1] = 1;
	dfs(1, 1, 1);
	cout<<ans+1<<endl;
	return 0;
}
