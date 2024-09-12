#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, m;
struct node {
	ll a, b;
} nodes[N];
bool cmp(node x, node y) {
	return x.a < y.a;
}
bool check(ll x) {
	ll pos = nodes[1].a, posf = 1;
	for (ll i = 2; i <= n; ++i) {
		if (pos + x <= nodes[posf].b) {
			pos += x;
		} else {
			while (posf <= m && pos + x > nodes[posf].b)
				++posf;
			if (pos + x > nodes[posf].b) 
				return false;
			pos = pos + x <= nodes[posf].a ? nodes[posf].a : pos + x;
		}
	}
	return true;
}
int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= m; ++i) 
		scanf("%lld%lld", &nodes[i].a, &nodes[i].b);
	sort(nodes + 1, nodes + m + 1, cmp);
	// Binary
	ll l = 1, r = nodes[m].b;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else 
			r = mid;
	}
	printf("%lld", l);
	return 0;
}
