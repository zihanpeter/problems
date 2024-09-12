#include <iostream>
#include <cstring>
using namespace std;
//price表示第i天第j个纪念品的价格 
int t, n, m, price[105][105], f[10005];
int main(){
	cin>>t>>n>>m;//天数、数量、本金
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>price[i][j];
		}
	} 
	for(int k=1;k<t;k++){//枚举天数 
		memset(f, 0, sizeof(f));//初始化 
		for(int i=1;i<=n;i++){//枚举物品 
			for(int j=1;j<=m;j++){//枚举价格 
				if(j >= price[k][i]){//买的起 
					f[j] = max(f[j], f[j-price[k][i]]+(price[k+1][i]-price[k][i]));
				}
			}
		}
		m += f[m];//更新总钱数 
	}
	cout<<m;
	return 0;
}
