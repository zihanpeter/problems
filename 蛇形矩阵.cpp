#include <iostream>
using namespace std;
int num[1000][1000];
int main(){
	int n;
	cin>>n;
	int i=0, j=0, count=0;
	num[i][j] = ++count;
	while(count < n*n){
		if(j < n-1){
			++j;
		}else{
			++i;
		}
		num[i][j] = ++count;
		while(i < n-1 && j > 0){
			++i;
			--j;
			num[i][j] = ++count;
		}
		if(i < n-1){
			++i;
		}else{
			++j;
		}
		num[i][j] = ++count;
		while(i > 0 && j < n-1){
			--i;
			++j;
			num[i][j] = ++count;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<num[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}