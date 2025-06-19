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
	for(int k=1;k<=n;k++){//��תվ 
		for(int i=1;i<=n;i++){//��� 
			for(int j=1;j<=n;j++){//�յ� 
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		if(g[i][i] < 0){//���ڸ��� 
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
