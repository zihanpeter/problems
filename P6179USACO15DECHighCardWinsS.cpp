#include <cstdio>
const int N = 1e5 + 5;
int n, a[N], b[N];
bool tong[N];
int main() {
	scanf("%d", &n);
	int t;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t);
		tong[t] = true;
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		if (tong[i]) 
			b[++cnt2] = i;
		else 
			a[++cnt1] = i;
	}
	int j = 1, ans = 0;
	for (int i = 1; i <= n; ++i) 
		if (a[i] > b[j]) {
			++j;
			++ans;
		}
	printf("%d", ans);
	return 0;
}
