#include <bits/stdc++.h>
using namespace std;
const int C = 1e6 + 5;
int n, tong[C];
int main() {
	scanf("%d", &n);
	int t, maxt = -0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t);
		maxt = max(maxt, t);
		++tong[t];
	}
	for (int i = maxt; i >= 1; --i) 
		tong[i] += tong[i + 1];
	long long maxAns = -0x3f3f3f3f3f3f3f3f;
	int ans;
	for (int i = maxt; i >= 1; --i) {
		long long cmp = 1ll * tong[i] * i;
		if (cmp >= maxAns) {
			maxAns = cmp;
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
} 
