#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int N = 35, INF = 0x3f3f3f3f;
int n, m, q, EXi, EYi, SXi, SYi, TXi, TYi, ans = INF;
int cx[] = {0, 0, 0, 1, -1}, cy[] = {0, 1, -1, 0, 0}, info[N][N], step[N][N], dis[N * N * 16];
bool vis[N][N];
struct node {
    int x, y;
};
queue<node> qx;
struct side {
    int x, w;
};
bool operator > (const side &x, const side &y) {
    return x.w > y.w;
}
vector<side> g[N * N * 16];
void bfs(int sx, int sy) {
    qx.push(node{sx, sy});
    while (!qx.empty()) {
        node x = qx.front();
        qx.pop();
        for (int i = 1; i <= 4; ++i) {
            int tx = cx[i] + x.x, ty = cy[i] + x.y;
            if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] || !info[tx][ty]) continue;
            vis[tx][ty] = true;
            step[tx][ty] = step[x.x][x.y] + 1;
            qx.push(node{tx, ty});
        }
    }
}
priority_queue<side, vector<side>, greater<side> > qy;
void dijkstra(int s) {
    for (int i = 1; i <= 900 * 16; ++i) dis[i] = INF;
    dis[s] = 0;
    qy.push(side{s, 0});
    while (!qy.empty()) {
        int x = qy.top().x;
        qy.pop();
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i].x, w = g[x][i].w;
            if (dis[x] + w < dis[y]) {
                dis[y] = dis[x] + w;
                qy.push(side{y, dis[y]});
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%d", &info[i][j]);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            if (!info[i][j]) continue;
            for (int k = 1; k <= 4; ++k) {
                int sx = i + cx[k], sy = j + cy[k];
                if (sx < 1 || sx > n || sy < 1 || sy > m || !info[sx][sy]) continue;
                memset(vis, 0, sizeof(vis));
                memset(step, 0x3f, sizeof(step));
                vis[i][j] = vis[sx][sy] = true;
                step[sx][sy] = 0;
                bfs(sx, sy);
                for (int l = 1; l <= 4; ++l) {
                    int tx = i + cx[l], ty = j + cy[l];
                    if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
                    int p1 = (m * (i - 1) + j) + k * 900, p2;
                    if (l == 1 || l == 2) p2 = ((tx - 1) * m + ty) + (3 - l) * 900;
                    else p2 = ((tx - 1) * m + ty) + (7 - l) * 900;
                    g[p1].push_back(side{p2, step[tx][ty] + 1});
                }
            }
        }
    while (q--) {
        scanf("%d%d%d%d%d%d", &EXi, &EYi, &SXi, &SYi, &TXi, &TYi);
        if (SXi == TXi && SYi == TYi) {
            printf("%d\n", 0);
            continue;
        }
        ans = INF;
        memset(vis, 0, sizeof(vis));
        memset(step, 0x3f, sizeof(step));
        vis[EXi][EYi] = vis[SXi][SYi] = true;
        step[EXi][EYi] = 0;
        bfs(EXi, EYi);
        for (int i = 1; i <= 4; ++i) {
            int tx = SXi + cx[i], ty = SYi + cy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || !info[tx][ty]) continue;
            int s = (m * (SXi - 1) + SYi) + i * 900;
            dijkstra(s);
            for (int j = 1; j <= 4; ++j) {
                int t = (m * (TXi - 1) + TYi) + j * 900;
                ans = ans < step[tx][ty] + dis[t] ? ans : step[tx][ty] + dis[t];
            } 
        }
        if (ans == INF) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}

