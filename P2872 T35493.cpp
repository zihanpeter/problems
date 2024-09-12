#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, x[N], y[N], cnt, f[N], cnt2;
double ans;
struct node {
	int u, v;
	double w;
} s[N * N];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]); 
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		s[++cnt].u = u; s[cnt].v = v;
		s[cnt].w = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			s[++cnt].u = i; s[cnt].v = j;
			s[cnt].w = (double)(sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (double)(y[i] - y[j]) * (y[i] - y[j])));
		}
	}
	sort(s + 1, s + cnt + 1, cmp);
	double w;
	for (int i = 1; i <= cnt; ++i) {
		u = s[i].u; v = s[i].v; w = s[i].w;
		if (find(u) == find(v)) continue;
		ans += w;
		++cnt2;
		f[find(u)] = find(v);
		if (cnt2 == n - 1) break;
	}
	printf("%.2lf", ans);
	return 0;
}
