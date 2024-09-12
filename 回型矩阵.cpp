#include <iostream>
using namespace std;
int a[2002][2002];
int main(){
	int n, i, j;
	cin>>n>>i>>j;
	int x=1, y=0, num=1;
	while(num <= n*n){
		while(y+1 <= n && a[x][y+1]==0){
			++y;
			a[x][y] = num;
			++num;
		}
		while(x+1 <= n && a[x+1][y]==0){
			++x;
			a[x][y] = num;
			++num;
		}
		while(y-1 >= 1 && a[x][y-1]==0){
			--y;
			a[x][y] = num;
			++num;
		}
		while(x-1 >= 1 && a[x-1][y]==0){
			--x;
			a[x][y] = num;
			num++;
		}
	}
	cout<<a[i][j];
	return 0;
}