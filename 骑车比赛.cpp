#include <iostream>
#include <queue>
using namespace std;
const int N = 1e2 + 5;
int n, m, g[N][N], dis[N];
bool vis[N];
struct node {
    int p, d;
};
bool operator > (const node &x, const node &y) {
    return x.d > y.d;
}
priority_queue<node, vector<node>, greater<node> > q;
int Dijkstra() {
    q.push(node{1, 0});
    while (!q.empty()) {
        int p = q.top().p;
        int d = q.top().d;
        q.pop();
        if (vis[p]) continue;
        vis[p] = true;
        dis[p] = d;
        for (int i = 1; i <= n; i++) 
            if (g[p][i] && !vis[i]) 
                q.push(node{i, g[p][i] + d});
    }
    return dis[n];
}

int main() {
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        g[x][y] = z;
        g[y][x] = z;
    }
    cout << Dijkstra() << endl;
    return 0;
}