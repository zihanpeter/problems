#include <iostream>
using namespace std;
int f[201], vis[201], k[201];
int head, tail, n, a, b;
struct node{
	int x, step;
}queue[40401];
void bfs(){
	queue[tail].x = a;
	queue[tail].step = 0;
	f[a] = 0;
	vis[a] = 1;
	while(head<=tail){
		int move = k[queue[head].x];
		int tx = queue[head].x + move;
		if(tx<=n && !vis[tx]){
			++tail;
			queue[tail].x = tx;
			queue[tail].step = queue[head].step + 1;
			f[tx] = queue[tail].step;
			vis[tx] = 1;
		}
		tx = queue[head].x - move;
		if(tx>=1 && !vis[tx]){
			++tail;
			queue[tail].x = tx;
			queue[tail].step = queue[head].step + 1;
			f[tx] = queue[tail].step;
			vis[tx] = 1;
		}
		++head;
	}
} 
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	if(a==b){
		cout<<0;
	}else{
		bfs();
		if(f[b]==0){
			cout<<-1;
		}else{
			cout<<f[b];
		}
	}
	return 0;
} 
