#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2e2 + 5;
int n, a, b, k[N];
bool vis[N];

struct node { int x, step; };
queue<node> q;

void bfs() {
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof(vis));
	vis[a] = true;
	q.push(node{a, 0});
	while (!q.empty()) {
		int x = q.front().x, step = q.front().step;
		if (x == b) {
			printf("%d\n", step);
			return;
		}
		q.pop();
		for (int i = -1; i <= 1; ++i) {
			if (!i) continue;
			int y = x + k[x] * i;
			if (y < 1 || y > n || vis[y]) continue;
			vis[y] = true;
			q.push(node{y, step + 1});
		}
	}
	printf("-1\n");
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= n; ++i) scanf("%d", k + i);
		bfs();
	}
	return 0;
}
