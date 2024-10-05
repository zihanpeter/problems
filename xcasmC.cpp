#include <iostream>
#include <queue>
using namespace std;

const int N = 3e2 + 5;

int n, sx, sy, fx, fy;
int cx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int cy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool vis[N][N];

struct node {
	int x, y, step;
};

queue<node> q;

void bfs() {
	vis[sx][sy] = true;
	q.push(node{sx, sy, 0});
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, step = q.front().step;
		if (x == fx && y == fy) {
			printf("%d", step);
			return;
		}
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int tx = cx[i] + x, ty = cy[i] + y;
			if (tx < 0 || tx >= n || ty < 0 || ty >= n || vis[tx][ty]) 
				continue;
			vis[tx][ty] = true;
			q.push(node{tx, ty, step + 1});
		}
	}
}

int main() {
	scanf("%d%d%d%d%d", &n, &sx, &sy, &fx, &fy);
	bfs();
	return 0;
}
