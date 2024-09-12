#include <iostream>
#include <vector>
using namespace std;
const int N = 2005, INF = 0x3f3f3f3f;
int n, d, a[N], w[N], c[N], g, temp[2][N], dp[N];
bool tong[N];
vector<int> gro[N];
int main() {
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; ++i) scanf("%d%d%d", a + i, w + i, c + i);
	scanf("%d", &g);
	for (int i = 1; i <= g; ++i) {
		int l, t;
		scanf("%d", &l);
		for (int j = 1; j <= l; ++j) {
			scanf("%d", &t);
			gro[i].push_back(t);
		}
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = temp[0][i] = temp[1][i] = -INF;
	}
	for (int i = 1; i <= g; ++i) {
		for (int j = 0; j < gro[i].size(); ++j) {
			int num = gro[i][j];
			tong[num] = true;
			for (int k = 0; k <= d; ++k) temp[0][k] = dp[k];
			if (a[num] == 0) {
				for (int k = c[num]; k <= d; ++k) 
					temp[0][k] = max(temp[0][k], temp[0][k - c[num]] + w[num]);
			} else {
				for (int t = 1; t <= a[num]; t <<= 1) {
					for (int k = d; k >= t * c[num]; --k) 
						temp[0][k] = max(temp[0][k], temp[0][k - t * c[num]] + t * w[num]);
					a[num] -= t;
				}
				if (a[num]) 
					for (int k = d; k >= a[num] * c[num]; --k) 
						temp[0][k] = max(temp[0][k], temp[0][k - a[num] * c[num]] + a[num] * w[num]);
			}
			for (int k = 0; k <= d; ++k) temp[1][k] = max(temp[1][k], temp[0][k]);
		}
		for (int j = 0; j <= d; ++j) dp[j] = temp[1][j];
	}
	for (int i = 1; i <= n; ++i) {
		if (!tong[i]) {
			if (a[i] == 0) {
				for (int k = c[i]; k <= d; ++k) 
					dp[k] = max(dp[k], dp[k - c[i]] + w[i]);
			} else {
				for (int t = 1; t <= a[i]; t <<= 1) {
					for (int k = d; k >= t * c[i]; --k) 
						dp[k] = max(dp[k], dp[k - t * c[i]] + t * w[i]);
					a[i] -= t;
				}
				if (a[i]) 
					for (int k = d; k >= a[i] * c[i]; --k) 
						dp[k] = max(dp[k], dp[k - a[i] * c[i]] + a[i] * w[i]);
			}
		}
	}
	if (dp[d] < 0) printf("i'm sorry...");
	else printf("%d", dp[d]);
	return 0;
}