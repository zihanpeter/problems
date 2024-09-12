#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, h[N], v[N], sum[N];
stack<int> s;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d%d", h + i, v + i);
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && h[s.top()] < h[i]) {
			sum[i] += v[s.top()];
			s.pop();
		}
		if (!s.empty()) 
			sum[s.top()] += v[i];
		s.push(i);
	}
	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) 
		ans = max(ans, sum[i]);
	printf("%d", ans);
	return 0;
} 
