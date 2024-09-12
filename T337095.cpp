#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, a[N], tree[N], low[N], upe[N], ans;
int lowbit(int x) {
	return x & -x;
}
void add(int x, int v) {
	while (x < n) {
		tree[x] += v;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while (x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for (int i = 1; i <= n; ++i) {
		add(a[i], 1);
		low[i] = query(a[i] - 1);
	}
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= n; ++i) a[i] = n - a[i] + 1;
	for (int i = n; i >= 1; --i) {
		add(a[i], 1);
		upe[i] = query(a[i] - 1);
	} 
	for (int i = 1; i <= n; ++i) ans += low[i] * upe[i];
	printf("%lld", ans);
	return 0;
} 
