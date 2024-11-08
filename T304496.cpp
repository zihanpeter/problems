#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, cnt, head[N], to[N << 1], nxt[N << 1], w[N << 1];

int main() {
	scanf("%d", &n);
	int u, v, w;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
    return 0;
}
