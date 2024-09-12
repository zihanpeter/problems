#include <iostream>
using namespace std;
int n;//����
int m;//����
int w[505];//����
int v[505];//��ֵ
int f[505][5005];//��������
int c[505];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int s;
		cin>>w[i]>>v[i]>>s;
		w[i] *= s;
		v[i] *= s;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j >= w[i]){
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]);
			}else{
				f[i][j] = f[i-1][j];
			}
		}
	}
	cout<<f[n][m]<<endl;
	for(int i=n;i>=1;i--){
		if(f[i][m] != f[i-1][m]){
			c[i] = 1;
			m -= w[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i] == 1){
			cout<<i<<' ';
		}
	}
	return 0;
}