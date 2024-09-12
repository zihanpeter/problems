#include <iostream>
using namespace std;
const int N = 2e3 + 5, MOD = 1e9 + 7;
int n, m, k, inv[N], mul[N], dvs[N];
int quickPow(int x, int y) {
	int ans = 1, t = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * t % MOD;
		t = 1ll * t * t % MOD, y >>= 1;
	}
	return ans;
}
void init() {
	for (int i = 1; i <= 2e3; ++i) inv[i] = quickPow(i, MOD - 2);
	inv[0] = mul[0] = dvs[0] = 1;
	inv[1] = mul[1] = dvs[1] = 1;
	for (int i = 2; i <= 2e3; ++i) {
		mul[i] = 1ll * i * mul[i - 1] % MOD;
		dvs[i] = 1ll * inv[i] * dvs[i - 1] % MOD;
	}
}

main() {
	scanf("%d%d%d", &n, &m, &k);
	init();
	if (n - 1 < 2 * k || m - 1 < 2 * k) printf("0");
	else printf("%d", 1ll * mul[n - 1] * dvs[n - 1 - 2 * k] % MOD * dvs[2 * k] % MOD * mul[m - 1] % MOD * dvs[m - 1 - 2 * k] % MOD * dvs[2 * k] % MOD);
	return 0;
}
