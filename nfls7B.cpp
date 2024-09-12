#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], l[N], r[N], p[N];
long long ans;
int pl[N], pr[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		for (int i = 1; i <= n; ++i) {
			l[i] = i - 1, r[i] = i + 1;
			p[a[i]] = i;
		}
		r[n + 1] = n + 1;
		for (int i = 1; i <= n; ++i) {
			int p1 = p[i], p2 = p[i];
			pl[1] = pr[1] = p[i];
			for (int j = 0; j <= k; ++j) {
				pl[j] = p1; p1 = l[p1];
				pr[j] = p2; p2 = r[p2];
			}
			for (int j = 1; j <= k; ++j) ans += 1ll * i * (pl[j - 1] - pl[j]) * (pr[k - j + 1] - pr[k - j]);
			r[l[p[i]]] = r[p[i]];
			l[r[p[i]]] = l[p[i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}