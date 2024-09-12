#include <iostream>
using namespace std;
int maze[5][5], vis[5][5]; 
struct node{
	int x, y, pre;
}queue[100];
int head, tail=-1;
int cx[4] = {0, 0, -1, 1};
int cy[4] = {-1, 1, 0, 0};
void print(int i){
	if(i==-1){
		return;
	}
	print(queue[i].pre);
	printf("(%d, %d)\n", queue[i].x, queue[i].y);
}
void bfs(){
	++tail;
	queue[tail].x = 0;
	queue[tail].y = 0;
	queue[tail].pre = -1;
	vis[0][0] = 1;
	while(head<=tail){
		for(int i=0;i<4;i++){
			int tx = cx[i] + queue[head].x;
			int ty = cy[i] + queue[head].y;
			if(tx<0 || tx>4 || ty<0 || ty>4 || vis[tx][ty]==1 || maze[tx][ty]==1){
				continue;
			}
			++tail;
			queue[tail].x = tx;
			queue[tail].y = ty;
			queue[tail].pre = head;
			vis[tx][ty] = 1;
			if(tx==4 && ty==4){
				print(head);
				printf("(4, 4)\n");
				return;
			} 
		}
		++head;
	}
}
int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>maze[i][j];
		}
	}
	bfs();
	return 0;
}
