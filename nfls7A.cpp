#include <iostream>
#include <queue>
using namespace std;
int n, m;
queue<int> q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) q.push(i);
	int t = 0;
	while (!q.empty()) {
		++t;
		if (t == m) {
			t = 0;
			printf("%d ", q.front());
			q.pop();
		} else {
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}