#include <iostream>
#include <string>
using namespace std;
int n, m;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int aa[505][505];
int a, b, c, d;
int ans = 0x3f3f3f3f;
void dfs(int x, int y, int cnt){
    if (x == c && y == d){
        ans = min(ans, cnt);
        return;
    }
    if (x<1 || x>n || y<1 || y>m || aa[x][y]=='#'){
        return;
    }
    if (cnt >= ans){
        return;
    }
    for (int i = 0;i < 4;i++){
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        aa[x][y] = '#';
        dfs(tx, ty, cnt+1);
        aa[x][y] = '.';
    }
}
int main(){
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
        string s;
        cin>>s;
        for (int j = 1;j <= m;j++){
            aa[i][j] = s[j-1];
        }
    }
    cin>>a>>b>>c>>d;
    dfs(a, b, 0);
    if (ans == 0x3f3f3f3f){
        cout<<-1;
    }else cout<<ans;
    return 0;
}
/*
#include <iostream>
using namespace std;
int n, m, a, b, c, d, head, tail;
int dx[4] = {0, 0, -1 ,1};
int dy[4] = {-1, 1, 0, 0};
char ai[505][505];
bool flag = false;
struct node{
    int x, y, step;
}que[250005];
void bfs(){
    que[tail].x = a;
    que[tail].y = b;
    que[tail].step = 0;
    ai[a][b] = '#';
    while (head <= tail){
        for (int i = 0;i < 4;i++){
            int tx = que[head].x + dx[i];
            int ty = que[head].y + dy[i];
            if (tx < 0 || tx > n-1 || ty < 0 || ty > m-1 || ai[tx][ty] == '#'){
                continue;
            }
            tail++;
            que[tail].x = tx;
            que[tail].y = ty;
            que[tail].step = que[head].step + 1;
            ai[tx][ty] = '#';
            if (tx == c  && ty == d){
                cout<<que[tail].step<<endl;
                flag = true;
                return;
            }
        }
        head++;
    }
    return;
}
int main(){
    cin>>n>>m;
    for (int i = 0;i < n;i++){
        cin>>ai[i];
    }
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    bfs();
    if (flag == false){
        cout<<-1<<endl;
    }
    return 0;
}
*/