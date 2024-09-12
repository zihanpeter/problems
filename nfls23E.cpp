#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, INF = 0x3f3f3f3f;
int n, m, s, t, cntp, cntd, dis[25][25];
bool vis[25][25];
char mat[25][25], st[25];
int cx[] = {1, -1, 0, 0}, cy[] = {0, 0, 1, -1};
struct node { int x, y; };
vector<node> g[25][25];
int cnt, nxt[N], head[N], to[N], wei[N], deep[N], now[N];
void add(int u, int v, int w) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; wei[cnt] = w; }
queue<int> q;
bool bfs() {
	memset(deep, 0, sizeof(deep));
	while (!q.empty()) q.pop();
	q.push(s);
	deep[s] = s;
	now[s] = head[s];
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = to[i], w = wei[i];
			if (deep[y] || !w) continue;
			deep[y] = deep[x] + 1;
			now[y] = head[y];
			if (y == t) return true;
			q.push(y);
		}
	}
	return false;
}
int dfs(int x, int flow) {
	if (x == t) return flow;
	int rest = flow, k;
	for (int i = now[x]; i && rest; i = nxt[i]) {
		int y = to[i], w = wei[i];
		now[x] = i;
		if (deep[y] ^ deep[x] + 1 || !w) continue;
		k = dfs(y, min(rest, w));
		if (!k) deep[y] = 0;
		wei[i] -= k;
		wei[i ^ 1] += k;
		rest -= k;
	}
	return flow - rest;
}
void bfs2(int sx, int sy) {
	queue<node> q;
	q.push(node{sx, sy});
	vis[sx][sy] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[sx][sy] = 0;
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = x + cx[i], ty = y + cy[i];
			if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] || mat[tx][ty] != '.') continue;
			vis[tx][ty] = true;
			if (dis[x][y] + 1 < dis[tx][ty]) dis[tx][ty] = dis[x][y] + 1;
			g[tx][ty].push_back(node{dis[tx][ty], cntd});
			q.push(node{tx, ty});
		}
	}
}
bool check(int mid) {
	cnt = 1;
	memset(head, 0, sizeof(head)); memset(now, 0, sizeof(now));
	s = cntp + cntd * mid + 1, t = cntp + cntd * mid + 2;
	for (int i = 1; i <= cntp; ++i) add(s, i, 1), add(i, s, 0);
	for (int i = 1; i <= cntd; ++i) for (int j = 1; j <= mid; ++j) {
		int dd = cntp + (i - 1) * mid + j;
		add(dd, t, 1), add(t, dd, 0);
		if (j < mid) add(dd, dd + 1, INF), add(dd + 1, dd, 0);
	}
	int cnt2 = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		if (mat[i][j] == '.') {
			++cnt2;
			for (int k = 0; k < g[i][j].size(); ++k) 
				if (g[i][j][k].x <= mid) {
					add(cnt2, cntp + (g[i][j][k].y - 1) * mid + g[i][j][k].x, 1);
					add(cntp + (g[i][j][k].y - 1) * mid + g[i][j][k].x, cnt2, 0);
				}
		}
	}
	int ans = 0;
	while (bfs()) ans += dfs(s, INF);
	// cout << mid << ' ' << ans << ' ' << cntp << endl;
	return ans >= cntp;
}
int main() {
	freopen("nfls23E.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", st + 1);
		for (int j = 1; j <= m; ++j) mat[i][j] = st[j];
	}
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) 
		if (mat[i][j] == 'D') {
			++cntd;
			bfs2(i, j);
		} else if (mat[i][j] == '.') ++cntp;
	int l = 1, r = 4e3, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	if (ans == -1) printf("impossible");
	else printf("%d", ans);
	return 0;
}
