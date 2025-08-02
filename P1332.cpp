#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 5, M = 5e2 + 5;
int n, m, a, b, vis[M][M];
int cx[] = {1, -1, 0, 0};
int cy[] = {0, 0, 1, -1};
struct node {
    int x, y;
};
queue<node> q;

void bfs() {
    node t;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = 3; ~i; --i) {
            int tx = t.x + cx[i], ty = t.y + cy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty]) continue;
            vis[tx][ty] = vis[t.x][t.y] == -1 ? 1 : vis[t.x][t.y] + 1;
            q.push(node{tx, ty});
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    int x, y;
    for (int i = 1; i <= a; ++i) {
        scanf("%d%d", &x, &y);
        vis[x][y] = -1;
        q.push(node{x, y});
    }
    bfs();
    for (int i = 1; i <= b; ++i) {
        scanf("%d%d", &x, &y);
        printf("%d\n", vis[x][y] == -1 ? 0 : vis[x][y]);
    }
    
    return 0;
}