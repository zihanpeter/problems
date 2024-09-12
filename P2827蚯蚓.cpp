#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, q, u, v, t, value;
queue<int> q1, q2;
int a[N];
priority_queue<int> ans;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
	for(int i=1; i<=n; i++) 
		scanf("%d", a + i);
	sort(a+1, a+n+1, cmp);
	a[n + 1] = -0x3f3f3f3f;
	int cntt = 1;
	for(int i=1; i<=m; i++) {
		if (!q1.empty() && !q2.empty()) {
			if (a[cntt] >= q1.front() && a[cntt] >= q2.front()) {
				int ta = a[cntt] + (i - 1) * q;
				if (i % t == 0) printf("%d ", ta);
				int tb = 1.0 * ta * u / v;
				int tc = ta - tb;
				q1.push(tb - i * q);
				q2.push(tc - i * q);
				cntt++;
			} else if (q1.front() >= a[cntt] && q1.front() >= q2.front()) {
				int ta = q1.front() + (i - 1) * q;
				q1.pop();
				if (i % t == 0) printf("%d ", ta);
				int tb = 1.0 * ta * u / v;
				int tc = ta - tb;
				q1.push(tb - i * q);
				q2.push(tc - i * q);
			} else {
				int ta = q2.front() + (i - 1) * q;
				q2.pop();
				if (i % t == 0) printf("%d ", ta);
				int tb = 1.0 * ta * u / v;
				int tc = ta - tb;
				q1.push(tb - i * q);
				q2.push(tc - i * q);
			}
		} else if (q1.empty() && q2.empty()) {
			int ta = a[cntt] + (i - 1) * q;
			if (i % t == 0) printf("%d ", ta);
			int tb = 1.0 * ta * u / v;
			int tc = ta - tb;
			q1.push(tb - i * q);
			q2.push(tc - i * q);
			cntt++;
		}
	}
	printf("\n");
	for (int i = cntt; i <= n; ++i) {
		ans.push(a[i] + m * q); 
	}
	while (!q1.empty()) {
		ans.push(q1.front() + m * q);
		q1.pop();
	}
	while (!q2.empty()) {
		ans.push(q2.front() + m * q);
		q2.pop();
	}
	int cnt = 0, ansc = 0;
	while (!ans.empty()) {
		++cnt;
		if (cnt % t == 0) {
			printf("%d ", ans.top());
			++ansc;
			if (ansc == (n + m) / t) break;
		}
		ans.pop();
	}
	return 0;
}
