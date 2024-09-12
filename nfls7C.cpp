#include <iostream>
#include <stack>
using namespace std;
const int N = 1e3 + 5;
int n, m, sum[N], lm[N], rm[N], ans;
char s[N][N];
stack<int> stk;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> s[i][j];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == 'R') sum[j] = 0;
			else ++sum[j];
		}
		while (!stk.empty()) stk.pop();
		for (int j = 1; j <= m; ++j) rm[j] = m + 1, lm[j] = 0;
		for (int j = 1; j <= m; ++j) {
			while (!stk.empty() && sum[stk.top()] > sum[j]) {
				rm[stk.top()] = j;
				stk.pop();
			}
			stk.push(j);
		}
		while (!stk.empty()) stk.pop();
		for (int j = m; j; --j) {
			while (!stk.empty() && sum[stk.top()] > sum[j]) {
				lm[stk.top()] = j;
				stk.pop();
			}
			stk.push(j);
		}
		for (int j = 1; j <= m; ++j) ans = max(ans, (rm[j] - lm[j] - 1) * sum[j]);
	}
	cout << ans * 3;
	return 0;
}
