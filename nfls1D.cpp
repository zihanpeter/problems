#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, INF = 0x3f3f3f3f;
int n, m, a[N], ans[N], maxt, pre[N];
void f(int t) {
	maxt = max(maxt, t);
	int cnt = 0, maxf = -INF, maxi = 0, flag = 0;
	vector<int> maxis;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == -1) continue;
		++flag;
		++cnt;
		if (a[i] > maxf) {
			maxf = a[i];
			maxi = i;
		}
		if (cnt == m) {
			cnt = 0;
			maxis.push_back(maxi);
			maxf = -INF;
		}
	}
	if (flag == 1) return;
	if (maxf != -INF) maxis.push_back(maxi);
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		if (~a[i] && i != maxis[p]) {
			ans[i] = t;
			a[i] = -1;
		}
		if (i == maxis[p]) ++p;
	}
	f(t + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	f(1);
	++maxt;
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == 0) ans[i] = 1;
		else ans[i] = maxt - ans[i];
	}
	for (int i = 1; i <= n; ++i) ++pre[ans[i]];
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + pre[i];
	for (int i = 1; i <= n; ++i) ans[i] = pre[ans[i] - 1] + 1;
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}
