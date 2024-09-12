#include <iostream>
using namespace std;
int list[33000];
long long n, m, a[20][20], num, f[20][2000];
void init() {
	for (int i = 0; i < (1 << m); ++i) {
		if ((i << 1) & i) 
			continue;
		list[++num] = i;
	}
	// cout << k << endl;
	return;
}
int main() {
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			cin >> a[i][j];
	for (int i = 1; i <= n; ++i) { // 枚举n�?
		for (int j = 1; j <= num; ++j) {
			long long sum = 0;
			for (int k = 1; k <= m; ++k) 
				if ((list[j] >> (k - 1)) & 1) 
					sum += a[i][k];
			for (int k = 1; k <= num; ++k) { // 枚举上一行的状�?
				if (list[j] & list[k]) continue; // 判断是否有相邻的	
				f[i][j] = max(f[i][j], f[i-1][k] + sum);
			}
		}
	}
	long long ans = -0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= num; ++i) 
		ans = max(f[n][i], ans);
	cout << ans << endl;
	return 0;
}
