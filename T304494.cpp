#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
int n, a[N];
ll midx;
bool check1(int x) {
	int i = 1;
	ll cnt = 0;
	for (int j = 1; j <= n; ++j) {
		while (a[i] <= a[j] + x && i <= n) ++i;
		cnt += n - i + 1;
	}
	return cnt * 2 > midx;
}
bool check2(int x) {
	int i = 1;
	ll cnt = 0;
	for (int j = 1; j <= n; ++j) {
		while (a[i] <= a[j] + x && i <= n) ++i;
		cnt += n - i + 1;
	}
	return cnt * 2 >= midx;
}
int main() {
	cin >> n;
	midx = 1ll * n * (n - 1) / 2;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = a[n] - a[1], mid, ans1, ans2;
	while (l <= r) {
		mid = l + r >> 1;
		if (check1(mid)) {
			ans1 = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	l = 0, r = a[n] - a[1];
	while (l <= r) {
		mid = l + r >> 1;
		if (check2(mid)) {
			ans2 = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << (ans1 + ans2) / 2;
	return 0;
} 
