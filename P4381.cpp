#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct node {
    int x, w;
};
vector<node> g[N];
vector<int> ring;
int n, rudu[N], cnt, lis[N], s[N], maxDis, visRing[N], root, dis[N], p, d[N], sr[N], anss;
bool vis[N];
queue<int> q;
deque<int> dq;

void getRing(int x, int fa, int fw) {
	int cntFa = 0, flag = true;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].x, w = g[x][i].w;
        if (y == fa) {
        	++cntFa;
			if (fw != w) flag = false;
			else {
				if (cntFa == 2 && !flag) continue;
				if (cntFa == 1) continue;
			}
		}
        if (!vis[y]) {
            if (visRing[y] == 2) return;
            ring.push_back(y);
            if (!lis[y]) lis[y] = ++cnt;
            else ++cnt;
            s[cnt] = s[cnt - 1] + w;
            ++visRing[y];
            getRing(y, x, w);
        }
    }
}

void dfs(int x, int fa) {
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].x, w = g[x][i].w;
        if (y == fa || !vis[y] && y != root) continue;
        dis[y] = dis[x] + w;
        if (dis[y] > maxDis) {
            maxDis = dis[y];
            p = y;
        }
        dfs(y, x);
    }
}

void topo() {
    for (int i = 1; i <= n; ++i) 
        if (rudu[i] == 1) {
            vis[i] = true;
            q.push(i);
        }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i].x;
            --rudu[y];
            if (rudu[y] == 1) {
                vis[y] = true;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && !visRing[i]) {
            cnt = 0;
            ring.clear();
            ring.push_back(i);
            lis[i] = ++cnt;
            visRing[i] = 1;
            getRing(i, 0, 0);
            int m = ring.size(), ans = 0;
            for (int j = 0; j < (ring.size() >> 1); ++j) {
                root = ring[j];
                maxDis = 0;
                p = 0;
                dis[root] = 0;
                dfs(root, 0);
                maxDis = 0;
                dis[p] = 0;
                dfs(p, 0);
                d[lis[root]] = maxDis;
                ans = max(ans, maxDis);
            }
            dq.clear();
            for (int i = 1; i <= m; ++i) {
                sr[i] = d[i] - s[i];
                ans = max(ans, d[i]);
            }
            for (int i = 1; i <= m; ++i) {
                if (!dq.empty()) ans = max(ans, d[i] + s[i] + sr[dq.back()]);
                else ans = max(ans, d[i] + s[i]);
                if (!dq.empty() && sr[dq.back()] < sr[i]) dq.pop_back();
                dq.push_back(i);
                if (!dq.empty() && dq.front() <= i - m) dq.pop_front();
            }
            anss += ans;
        }
    }
}

int main() {
	freopen("P4381.in", "r", stdin);
    scanf("%d", &n);
    int x, w;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &w);
        g[i].push_back(node{x, w});
        g[x].push_back(node{i, w});
        ++rudu[i];
        ++rudu[x];
    }
    topo();
    printf("%d", anss);
    return 0;
}
