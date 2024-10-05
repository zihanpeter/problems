#include <iostream>
using namespace std;
const int N = 1e4 + 5;
int n, k, l, r, ans;
double maxf, a[N];
bool check(double mid) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += a[i] / mid;
	if (cnt >= k) return true;
	return false;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i){
		scanf("%lf", &a[i]);
		maxf = max(a[i], maxf);
	}
	l = 0, r = maxf * 100;
	while (l <= r) {
		int mid = (l + r) >> 1;
		double miid = mid / 100.0;
		if (check(miid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	if (ans == 0) printf("0.00");
	else {
		double anser = ans / 100.0;
		printf("%.2lf", anser);
	}
	return 0;
} 