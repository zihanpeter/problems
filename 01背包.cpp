#include <iostream>
using namespace std;
int n, m;
int w[1001], c[1001];
int f[1001][1001];
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j>=w[i]){
				f[i][j] = max(f[i-1][j], c[i]+f[i-1][j-w[i]]);
			}else{
				f[i][j] = f[i-1][j];
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
//Ò»Î¬Êý×é°æ
#include <iostream>
using namespace std;
int n, m;
int w[10001], c[10001];
int f[1000001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j>=w[i]){
				f[j] = max(f[j], c[i]+f[j-w[i]]);
			}
		}
	}
	cout<<f[m];
	return 0;
}

