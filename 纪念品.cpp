#include <iostream>
#include <cstring>
using namespace std;
//price��ʾ��i���j������Ʒ�ļ۸� 
int t, n, m, price[105][105], f[10005];
int main(){
	cin>>t>>n>>m;//����������������
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>price[i][j];
		}
	} 
	for(int k=1;k<t;k++){//ö������ 
		memset(f, 0, sizeof(f));//��ʼ�� 
		for(int i=1;i<=n;i++){//ö����Ʒ 
			for(int j=1;j<=m;j++){//ö�ټ۸� 
				if(j >= price[k][i]){//����� 
					f[j] = max(f[j], f[j-price[k][i]]+(price[k+1][i]-price[k][i]));
				}
			}
		}
		m += f[m];//������Ǯ�� 
	}
	cout<<m;
	return 0;
}
