#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, c, l, ans, t;
main() {
	scanf("%lld%lld%lld%lld", &a, &b, &c, &l);
	for (int i = 0; i <= l; ++i) 
		ans += (i + 2) * (i + 1) / 2;
	for (int i = 0; i <= l; ++i) {
		t = min(l - i, c + i - a - b);
		if (t >= 0) ans -= (t + 2) * (t + 1) / 2;
		t = min(l - i, a + i - b - c);
		if (t >= 0) ans -= (t + 2) * (t + 1) / 2;
		t = min(l - i, b + i - a - c);
		if (t >= 0) ans -= (t + 2) * (t + 1) / 2;
	}
	printf("%lld", ans);
	return 0;
}