#include <iostream>
using namespace std;
const int N = 1e4 + 5, INF = 0x3f3f3f3f;
int n, m, si[N], pos[N], s, t;
int cnt = 1, head[N], nxt[N], to[N], wei[N], cost[N];

void add(int u, int v, int w, int c) {
	nxt[++cnt] = head[u]; to[cnt] = v; head[u] = cnt; wei[cnt] = w; cost[cnt] = c;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		if (i ^ 1 && i ^ n) add(i, 2 * i, 1, 1), add(2 * i, i, 0, -1);
		else add(i, 2 * i, 2, 1), add(2 * i, i, 0, -1);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", si + i); pos[si[i]] = i;
	}
	int u, v;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &u, &v);
		if (pos[u] < pos[v]) {
			add(u * 2, v, )
		} else {

		}
	}
	return 0;
}
