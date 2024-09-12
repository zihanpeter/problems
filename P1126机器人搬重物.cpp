#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, info[N][N], bx, by, ex, ey, bbface;
char bface;
bool vis[N][N];
struct node {
    int x, y, face;
};
queue<node> q;
void bfs() {
    q.push(node{bx, by, bbface});
    vis[bx][by] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int face = q.front().face;
        for (int i = 0; i < 4; ++i) { // Ã¶¾Ùface
            
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j)
            cin >> info[i][j];
    cin >> bx >> by >> ex >> ey >> bface;
    ++bx; ++by; ++ex; ++ey;
    if (bface == 'N')
        bbface = 0;
    else if (bface == 'E')
        bbface = 1;
    else if (bface == 'S')
        bbface = 2;
    else 
        bbface = 3;
    bfs();
    return 0;
}