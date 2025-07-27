#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 5, M = 5e2 + 5;
int n, m, a, b, mp[M][M], vis[M][M];
struct node {
    int x, y;
};
queue<node> q;

void bfs() {
    node t;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    int x, y;
    for (int i = 1; i <= a; ++i) {
        scanf("%d%d", &x, &y);
        mp[x][y] = -1;
        q.push(node{x, y});
    }
    for (int i = 1; i <= b; ++i) {
        scanf("%d%d", &x, &y);
        mp[x][y] = -2;
    }
    bfs();
    return 0;
}