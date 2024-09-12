#include <iostream>
using namespace std;
int n;
int g[505][505];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	for(int k=1;k<=n;k++){//中转站 
		for(int i=1;i<=n;i++){//起点 
			for(int j=1;j<=n;j++){//终点 
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		if(g[i][i] < 0){//存在负环 
			cout<<"No Solution"<<endl; 
			return 0;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
