#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, m1, m2, a[N], b[N], jc[N], ijc[N];
int qp(int x, int y) {
	int ans = 1, t = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * t % MOD;
		y >>= 1, t = 1ll * t * t % MOD;
	}
	return ans;
}
void init() {
	jc[0] = ijc[0] = 1;
	for (int i = 1; i <= 2e5; ++i) {
		jc[i] = jc[i - 1] * i % MOD;
		ijc[i] = ijc[i - 1] * qp(i, MOD - 2) % MOD;
	}
}
int C(int n, int m) {
	if (n < m) return 0;
	return jc[n] * ijc[m] % MOD * ijc[n - m] % MOD;
}
main() {
	int t;
	scanf("%lld", &t);
	init();
	while (t--) {
		scanf("%lld%lld%lld", &n, &m1, &m2);
		for (int i = 1; i <= m1; ++i) scanf("%lld", a + i);
		for (int i = 1; i <= m2; ++i) scanf("%lld", b + i);
		if (a[1] != 1 || a[m1] != b[1] || b[m2] != n) {
			printf("0\n");
			continue;
		}
		int ans = C(n - 1, a[m1] - 1);
		for (int i = m1 - 1; i; --i) 
			ans = ans * C(a[i + 1] - 2, a[i] - 1) % MOD * jc[a[i + 1] - a[i] - 1] % MOD;
		for (int i = 2; i <= m2; ++i) 
			ans = ans * C(n - b[i - 1] - 1, n - b[i]) % MOD * jc[b[i] - b[i - 1] - 1] % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}