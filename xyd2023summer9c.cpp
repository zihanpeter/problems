#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e4 + 5, INF = 0x3f3f3f3f;
int n, m, k, s, t, dis[N][15];
struct node {
	int x, w, c;
};
bool operator > (const node &x, const node &y) {
	return x.w > y.w;
}
priority_queue<node, vector<node>, greater<node> > q;
vector<node> g[N];
void dijkstra() {
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= k; ++j) dis[i][j] = INF;
	dis[s][0] = 0;
	q.push(node{s, 0, 0});
	while (!q.empty()) {
		int x = q.top().x, c = q.top().c;
		q.pop();
		for (int i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].x, w = g[x][i].w;
			if (c < k && dis[x][c] < dis[y][c + 1]) {
				dis[y][c + 1] = dis[x][c];
				q.push(node{y, dis[y][c + 1], c + 1});
			}
			if (dis[x][c] + w < dis[y][c]) {
				dis[y][c] = dis[x][c] + w;
				q.push(node{y, dis[y][c], c});
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    if (s == t) {
        printf("0");
        return 0;
    }
	int u, v, w;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(node{v, w});
		g[v].push_back(node{u, w});
	}
	dijkstra();
    int ans = INF;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, dis[t][i]);
    }
    printf("%d", ans);
	return 0;
}
