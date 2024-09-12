#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], p1[N], p2[N], p3[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		a[i] == 1 ? p1[i] = p1[i - 1] + 1 : p1[i] = p1[i - 1];
		a[i] == 2 ? p2[i] = p2[i - 1] + 1 : p2[i] = p2[i - 1];
		a[i] == 3 ? p3[i] = p3[i - 1] + 1 : p3[i] = p3[i - 1];
	}
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		printf("%d %d %d\n", p1[r] - p1[l - 1], p2[r] - p2[l - 1], p3[r] - p3[l - 1]);
	}
	return 0;
}
