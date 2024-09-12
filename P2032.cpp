#include <iostream>
#include <deque>
using namespace std;
const int N = 2e6 + 5;
int n, k, a[N];
deque<int> q;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
		q.push_back(i);
		if (i >= k) {
			while (!q.empty() && q.front() <= i - k) q.pop_front();
			printf("%d\n", a[q.front()]);
		}
	}
	return 0;
}
