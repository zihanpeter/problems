#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5, INF = 0x3f3f3f3f3f3f3f3f;
int f, p, cnt, nxt[N], head[N], to[N], wei[N], deep[N], now[N], g[505][505];
int num[N], cap[N], sumCow, s, t;
void add(int u, int v, int w) {
    nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; wei[cnt] = w;
}
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

bool check(int mid) {
    cnt = 1;
    memset(head, 0, sizeof(head));
    memset(now, 0, sizeof(now));
    // cout << "--------" << endl;
    // cout << mid << endl;
    for (int i = 1; i <= f; ++i) {
        add(s, i, num[i]);
        // cout << 's' << i << ' ' << num[i] << endl;
        add(i, s, 0);
        add(i + f, t, cap[i]);
        // cout << i << 't' << ' ' << cap[i] << endl;
        add(t, i + f, 0);
    }
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= f; ++j) {
            if (g[i][j] <= mid) {
                add(i, j + f, INF);
                // cout << i << ' ' << j << endl;
                add(j + f, i, 0);
            }
        }
    }
    int ans = 0;
    while (bfs()) ans += dfs(s, INF);
    // cout << mid << ' ' << ans << endl;
    // cout << sumCow << endl;
    return ans == sumCow;
}

main() {
    scanf("%lld%lld", &f, &p);
    for (int i = 1; i <= f; ++i) {
        scanf("%lld%lld", num + i, cap + i);
        sumCow += num[i];
    }
    s = 2 * f + 1, t = 2 * f + 2;
    int u, v, w;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= p; ++i) {
        scanf("%lld%lld%lld", &u, &v, &w);
        g[u][v] = g[v][u] = min(g[v][u], w);
    }
    for (int i = 1; i <= f; ++i) g[i][i] = 0;
    for (int k = 1; k <= f; ++k) 
        for (int i = 1; i <= f; ++i) 
            for (int j = 1; j <= f; ++j) 
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    printf("%lld", ans);
    return 0;
}