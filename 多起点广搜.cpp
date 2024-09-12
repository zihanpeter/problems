#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int aa[10000][1];
int f[505][505];
struct node{
    int x, y, step;
}que[155025];
int head, tail=-1;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void bfs(){
    while (head <= tail){
        for (int i = 0;i < 4;i++){
            int tx = que[head].x + dx[i];
            int ty = que[head].y + dy[i];
            if (tx<1 || tx>n || ty<1 || ty>m || f[tx][ty]!=0){
                continue;
            }
            tail++;
            que[tail].x = tx;
            que[tail].y = ty;
            que[tail].step = que[head].step+1;
            f[tx][ty] = que[tail].step;
        }
        head++;
    }
}
int main(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i=1;i<=a;i++){
    	int x, y;
    	scanf("%d %d", &x, &y);
    	++tail;
    	que[tail].x = x;
    	que[tail].y = y;
    	que[tail].step = 0;
    	f[x][y] = -1;
	}
	bfs();
	for(int i=1;i<=b;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(f[x][y]==-1){
			printf("0\n");
		}else printf("%d\n", f[x][y]);
	}
    return 0;
}
/*
5 4 2 3
1 1
5 4
3 3
5 3
2 4
*/
